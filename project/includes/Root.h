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

	WindowManager* mWindowManager;
	RenderManager* mRenderManager;
	InputManager* mInputManager;

	std::vector<Actor*> mActors;
	std::vector<Actor*> mPendingActors;
	
	bool GameState;
	bool UpdatingActors;
};