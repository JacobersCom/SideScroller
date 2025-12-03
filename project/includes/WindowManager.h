#pragma once

#include "Defines.h"
#include <chrono>

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
	std::chrono::steady_clock::time_point lastFrame;
};

