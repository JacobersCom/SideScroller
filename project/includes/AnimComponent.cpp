#include "AnimComponent.h"

AnimComponent::AnimComponent(Actor* owner, int drawOrder)
	: SpriteComponent(owner, drawOrder)
{
	this->mCurrFrame = 0.0f;
	this->mFPS = 24.0f;
}

void AnimComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	if (vecTextures.empty()) { return; }
	
	//Updates based on deltaTime
	mCurrFrame += mFPS * deltaTime;
			
	//Wraps the texture back to 0
	if (mCurrFrame >= vecTextures.size())
	{
		mCurrFrame -= vecTextures.size();
		mCurrFrame < 0 ? 0 : mCurrFrame;
	}

	int iter = static_cast<int>(mCurrFrame);
	AnimComponent::SetTexture(vecTextures[iter]);
	
}


