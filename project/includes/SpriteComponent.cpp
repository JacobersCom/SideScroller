#include "SpriteComponent.h"

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
	mTexture = texture;
	SDL_GetTextureProperties(mTexture);
	mTextHeight = mTexture->h;
	mTextWidth = mTexture->w;
}

SDL_Texture* SpriteComponent::LoadTexture(const char* fileName)
{
	SDL_Surface* surf = IMG_Load(fileName);

	if (!surf)
	{
		SDL_Log("ERROR Failed to load surface %s", fileName);
		return nullptr;
	}

	SDL_Texture* text = SDL_CreateTextureFromSurface(mRenderManager->renderer, surf);
	SDL_DestroySurface(surf);
	if (!text)
	{
		SDL_Log("ERROR: Failed to convert surface to texture for %s", fileName);
		return nullptr;
	}
	return text;
}
