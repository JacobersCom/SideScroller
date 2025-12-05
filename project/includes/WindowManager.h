#pragma once

#include "Defines.h"


class WindowManager
{
public:

	WindowManager();
	bool Initialize();
	void GameLoop();
	void ShutDown();

	void UpdateGame();

private:


	SDL_Window* window;
	bool isRunning;
	
};

