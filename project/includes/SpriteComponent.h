#pragma once

#pragma region Includes

#include "Componet.h"
#include "RenderManager.h"
#include "SDL3_image/SDL_image.h"

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

	//Order in which the sprite is called to be drawn
	int mDrawOrder;
		
	int mTextWidth;	
	int mTextHeight;

private:

	std::unique_ptr<RenderManager> mRenderManager;

};