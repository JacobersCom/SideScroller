#pragma once

#include "Defines.h"

class WindowManager
{
public:

	WindowManager();
	bool Initialize();
	void Update();
	void ShutDown();


private:
	SDL_Window* window;
	bool isRunning;
};

