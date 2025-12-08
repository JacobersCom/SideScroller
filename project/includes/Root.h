#pragma once

#include "WindowManager.h"
#include "RenderManager.h"

class Root
{
public:

	Root();

	bool Initialize();
	void GameLoop();
	void ShutDown();

private:
	bool isRunning;
	WindowManager* mWindowManager;
	RenderManager* mRenderManager;
};