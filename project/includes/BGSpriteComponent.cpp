#include "BGSpriteComponent.h"

BGSpriteComponent::BGSpriteComponent(Actor* player, int drawOrder)
	: SpriteComponent(player, drawOrder)
{
	this->mScreenSize = { 0, 0 };
	this->mScrollSpeed = 0.0f;
}

void BGSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	for (auto& bg : mBGtextures)
	{
		bg.mOffset.x += mScrollSpeed * deltaTime;

		if (bg.mOffset.x < -mScreenSize.x)
		{
			bg.mOffset.x = (mBGtextures.size() - 1) * mScreenSize.x -1;
		}
	}
}

void BGSpriteComponent::SetBGTexture(std::vector<SDL_Texture*>& textures)
{
	int count = 0;
	for (auto text : textures)
	{
		BGTextures temp;
		temp.mTexture = text;
		temp.mOffset.x = count * mScreenSize.x;
		temp.mOffset.y = 0;
		mBGtextures.emplace_back(temp);
		count++;
	}
}
