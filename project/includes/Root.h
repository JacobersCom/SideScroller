#pragma once

#include "WindowManager.h"
#include "RenderManager.h"
#include "InputManager.h"

#include "Actor.h"

class Root
{
public:

	Root();
	~Root();

	bool Initialize();
	void GameLoop();
	void ShutDown();

	void AddActor(Actor* mActor);
	void RemoveActor(Actor* mActor);

private:

	bool GameState;
	WindowManager* mWindowManager;
	RenderManager* mRenderManager;
	InputManager* mInputManager;

	std::vector<Actor*> mActors;
	std::vector<Actor*> mPendingActors;
};