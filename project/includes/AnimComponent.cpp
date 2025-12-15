#include "AnimComponent.h"

void AnimComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	if (vecTextures.size() > 0)
	{
		mCurrFrame += mFPS * deltaTime;

		if (mCurrFrame >= vecTextures.size())
		{
			mCurrFrame -= vecTextures.size();
		}

		//Fix it
		SetTexture(vecTextures[static_cast<int>(mCurrFrame)]);
	}
}
