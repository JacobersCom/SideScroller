#pragma once

#include "WindowManager.h"
#include "RenderManager.h"
#include "InputManager.h"

#include "SpriteComponent.h"

#include <vector>

class Root
{
public:

	Root();
	~Root();

	bool Initialize();
	void GameLoop();
	void ShutDown();

	void AddActor(class Actor* mActor);
	void RemoveActor(class Actor* mActor);
	void UpdateActor();

	void AddSprite(class SpriteComponent* mSprite);

private:

	WindowManager* mWindowManager;
	RenderManager* mRenderManager;
	InputManager* mInputManager;

	std::vector<Actor*> mActors;
	std::vector<Actor*> mPendingActors;
	std::vector<SpriteComponent*> mSprites;
	
	bool GameState;
	bool UpdatingActors;
};