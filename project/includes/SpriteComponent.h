#pragma once

#include "Componet.h"
#include "RenderManager.h"
#include "SDL3_image/SDL_image.h"


class SpriteComponent : public Component
{
public:

	SDL_Texture* LoadTexture(const char* fileName);
	

private:

	std::unique_ptr<RenderManager> mRenderManager;

};