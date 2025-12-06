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

//Member fields

	SDL_Window* window;
	bool isRunning;
	
};

