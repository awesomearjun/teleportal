#pragma once

#include "ECS.hpp"
#include "vecmath/vector.hpp"

class TransformComponent : public Component
{
public:
	vcm::vec2 position;
	vcm::vec2 velocity;
	vcm::vec2 size;

	TransformComponent();
	TransformComponent(vcm::vec2 p_position, vcm::vec2 p_velocity, vcm::vec2 p_size);

	void update() override
	{
		position += velocity;
	}

	~TransformComponent() override = default;
};
