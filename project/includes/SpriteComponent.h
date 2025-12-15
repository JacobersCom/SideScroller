#pragma once

#pragma region Class_Includes

#include "Componet.h"
#include "RenderManager.h"
#include "SDL3_image/SDL_image.h"
#include "Defines.h"

#pragma endregion

#pragma region lib_Includes

#pragma endregion


class SpriteComponent : public Component
{
public:

	SpriteComponent(class Actor* actor, int draworder = 100);
	~SpriteComponent();

	//Overridable
	virtual void Draw(SDL_Renderer* render);

	//Overridable
	virtual void SetTexture(SDL_Texture* texture);

	SDL_Texture* LoadTexture(const char* fileName);
	
	//Getters/Setters
	int GetDrawOrder() const { return mDrawOrder; }

	int GetTextHeight() const { return mTextHeight; }

	int GetTextWidth() const { return mTextWidth; }

protected:

	SDL_Texture* mTexture;

	int mDrawOrder;
		
	int mTextWidth;	
	int mTextHeight;

private:

	std::unique_ptr<RenderManager> mRenderManager;

};