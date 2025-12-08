#pragma once

#include "WindowManager.h"
#include "RenderManager.h"
#include "InputManager.h"

class Root
{
public:

	Root();
	~Root();

	bool Initialize();
	void GameLoop();
	void ShutDown();


private:

	bool GameState;
	WindowManager* mWindowManager;
	RenderManager* mRenderManager;
	InputManager* mInputManager;
};