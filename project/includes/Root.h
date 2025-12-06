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

private:

	WindowManager* mWindowManager;
	RenderManager* mRenderManager;
};