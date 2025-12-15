#pragma once

#pragma region Class_Includes

#include "SpriteComponent.h"

#pragma endregion

class BGSpriteComponent : public SpriteComponent
{
public: 

	//Lower so its in the back ground
	BGSpriteComponent(class Actor*, int drawOrder = 10);

	void Update(float deltaTime) override;

	void Draw(SDL_Renderer* renderer) override;

	void SetBGTexture(std::vector<SDL_Texture*>& textures);

	void SetScreenSize(const vec2& size) { mScreenSize = size; }

	void SetScrollSpeed(float speed) { mScrollSpeed = speed; }
	
	float GetScrollSpeed() { return mScrollSpeed; }

private:

	float mScrollSpeed;

	vec2 mScreenSize;

	std::vector<SDL_Texture*> mBGtextures;

	struct BGTextures
	{
		SDL_Texture* mTexture;
		vec2 mOffset;
	};
};