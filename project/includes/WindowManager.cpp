#include "WindowManager.h""

WindowManager::WindowManager()
{
	window = nullptr;
	isRunning = false;
}

bool WindowManager::Initialize()
{
	if (!SDL_INIT_VIDEO)
	{
		SDL_Log("ERROR: Failed to initialize video system: %s\n", SDL_GetError());
		return false;
	}

	window = SDL_CreateWindow("SideScroller", screen_W, screen_H, NULL);

	if (!window)
	{
		SDL_Log("ERROR: Failed to create window: %s\n", SDL_GetError());
		return false;
	}
	
	return true;
}


void WindowManager::ShutDown()
{
	SDL_DestroyWindow(window);

	SDL_Quit();
}