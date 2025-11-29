#pragma once

#include "Defines.h"

class WindowManager
{
public:

	WindowManager();
	bool Initialize();
	void ShutDown();


protected:
	SDL_Window* window;
	bool isRunning;
};

