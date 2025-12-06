#pragma once

#include "WindowManager.h"
#include "RenderManager.h"

class Root
{
public:

	Root();
	~Root();

	bool initalize();
	void GameLoop();
	void ShutDown();

private:
	bool isRunning;
	WindowManager* mWindowManager;
	RenderManager* mRenderManager;
};