#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(Actor* actor, int draworder)
{
	//How would you create a new sprite Component?
}

SpriteComponent::~SpriteComponent()
{
	//What would happen after the sprite compoenet is destroyed?
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{

	//if mTexture is not null
	if (mTexture)
	{
		SDL_FRect r;

		//Scale by the onwer's size
		r.w = static_cast<int>(mTextWidth * mOwner->GetScale());
		r.h = static_cast<int>(mTextWidth * mOwner->GetScale());

		// center the rect around the owner you will need to add - r / 2 but see what this does
		r.x = static_cast<int>(mOwner->GetPosition().x);
		r.y = static_cast<int>(mOwner->GetPosition().y);

	
		SDL_RenderTextureRotated(renderer, mTexture, nullptr, &r, ToDegrees(mOwner->GetRotation()), nullptr, SDL_FLIP_NONE);
	}
}

// move this to Root.h
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
