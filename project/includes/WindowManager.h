#pragma once

#include "Defines.h"

class WindowManager
{
public:

	WindowManager();
	bool Initialize();
	void Update();
	bool ShutDown();


private:
	SDL_Window* window;
	bool isRunning;
};

