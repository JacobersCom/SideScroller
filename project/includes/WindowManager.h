#pragma once

#include "Defines.h"
#include "SDL3/SDL.h"

#include <iostream>
#include <chrono>


class WindowManager
{
public:

	WindowManager();
	~WindowManager();

	bool Initialize();
	void GameLoop();
	void ShutDown();

	void UpdateGame();

//Member fields


	SDL_Window* window;
	bool isRunning;
	
};

