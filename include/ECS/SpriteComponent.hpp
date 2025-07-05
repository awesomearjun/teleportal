#pragma once

#include "ECS.hpp"

#include "ECS/TransformComponent.hpp"
#include "SDL.h"
#include <memory>
#include <string>

class SpriteComponent : public Component
{
public:
	SpriteComponent(std::string filePath);
	void init() override;
	void update() override;
	~SpriteComponent() override;
private:
	SDL_Texture *sprite;

	std::shared_ptr<TransformComponent> transform;

	SDL_Rect dstRect;
};
