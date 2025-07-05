#include "ECS/ECS.hpp"
#include <memory>
#include <utility>

ComponentID getNewComponentTypeID()
{
    static ComponentID lastID = 0u;
    return lastID++;
}

Entity::Entity(Manager &p_manager) : m_manager(p_manager) {}

void Entity::update()
{
    for (auto &c : m_componentArray)
    {
        if (c == nullptr)
            continue;
        c->update();
    }
}

bool Entity::isActive() const { return m_active; }

void Entity::destroy() { m_active = false; }

void Manager::init()
{
    for (auto &e : m_entities)
        e->update();
}

void Manager::update()
{
    for (auto &e : m_entities)
        e->update();
}

Entity &Manager::addEntity()
{
    Entity *e = new Entity(*this);
    std::unique_ptr<Entity> uPtr{e};
    m_entities.emplace_back(std::move(uPtr));
    return *e;
}
