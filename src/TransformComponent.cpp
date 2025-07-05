#include "ECS/TransformComponent.hpp"
#include "vecmath/vector.hpp"

TransformComponent::TransformComponent(vcm::vec2 p_position,
                                       vcm::vec2 p_velocity, vcm::vec2 p_size)
{
    position = p_position;
    velocity = p_velocity;
    size = p_size;
}
