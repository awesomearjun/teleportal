#include "ECS/SpriteComponent.hpp"

#include "ECS/Components.hpp"
#include "ECS/TransformComponent.hpp"
#include "SDL_render.h"
#include "game.hpp"
#include "resourceLoader.hpp"
#include <memory>
#include <iostream>

SpriteComponent::SpriteComponent(std::string filePath)
{
    sprite = ResourceLoader::loadTexture(filePath);
}

void SpriteComponent::init()
{
	
}

void SpriteComponent::update()
{
    transform = entity->getComponent<TransformComponent>();

	if (transform == nullptr)
	{
		std::cerr << "Transform is null" << std::endl;
	}

    dstRect.x = transform->position.x;
    dstRect.y = transform->position.y;
    dstRect.w = transform->size.x;
    dstRect.h = transform->size.y;

    SDL_RenderCopy(Game::gameRenderer, sprite, NULL, &dstRect);
}

SpriteComponent::~SpriteComponent() { SDL_DestroyTexture(sprite); }
