#pragma once

#include <array>
#include <bitset>
#include <cstddef>
#include <memory>
#include <vector>

class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;

ComponentID getNewComponentTypeID();

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeID{getNewComponentTypeID()};
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<std::shared_ptr<Component>, maxComponents>;

class Component
{
public:
    Entity *entity;

    virtual void init() {}
    virtual void update() {}

    virtual ~Component() = default;
};

class Entity
{
public:
    Entity(Manager &p_manager);

    void update();
    bool isActive() const;
    void destroy();

    template <typename T> bool hasComponent() const
    {
        return m_componentBitSet[getComponent<T>()];
    }

    template <typename T, typename... TArgs> void addComponent(TArgs &&...mArgs)
    {
        std::shared_ptr<Component> component =
            std::make_shared<T>(std::forward<TArgs>(mArgs)...);

        component->entity = this;

		component->init();

        m_componentArray[getComponentTypeID<T>()] = component;
        m_componentBitSet[getComponentTypeID<T>()] = true;
    }

    template <typename T> std::shared_ptr<T> getComponent() const
    {
        auto ptr(m_componentArray[getComponentTypeID<T>()]);
        return std::static_pointer_cast<T>(ptr);
    }

private:
    Manager &m_manager;
    bool m_active = true;
    ComponentArray m_componentArray;
    ComponentBitSet m_componentBitSet;
};

class Manager
{
public:
	void init();
    void update();
    void refresh();
    Entity &addEntity();

private:
    std::vector<std::unique_ptr<Entity>> m_entities;
};
