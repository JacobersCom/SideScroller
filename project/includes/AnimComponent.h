#pragma once

#pragma region Class_Includes

#include "SpriteComponent.h"


#pragma endregion

class AnimComponent : public SpriteComponent
{
public :

	AnimComponent(class Actor* owner, int drawOrder = 100);

	//why override?
	void Update(float deltaTime) override;

	void SetTexture(const SDL_Texture* vecTextures);

	//Getters/Setters
	float GetAnimFPS() const { return mFPS; }

	void SetAnimFPS(float fps) { mFPS = fps; }

private:

	std::vector<SDL_Texture*> vecTextures;

	float mFPS;

	float mCurrFrame;

};