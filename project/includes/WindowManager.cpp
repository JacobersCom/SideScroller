#include "WindowManager.h""
#include "Root.h"

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif


WindowManager::WindowManager()
{
	isRunning = false;
	window = nullptr;
}

bool WindowManager::Initialize()
{
	if (!SDL_INIT_VIDEO)
	{
		SDL_Log("ERROR: Failed to initialize video system: %s\n", SDL_GetError());
	}

	window = SDL_CreateWindow("SideScroller", screen_W, screen_H, NULL);

	if (!window)
	{
		SDL_Log("ERROR: Failed to create window: %s\n", SDL_GetError());
	}
	
	return isRunning = true;
}


void WindowManager::GameLoop()
{
	while (isRunning)
	{
		UpdateGame();
	}
}


void WindowManager::UpdateGame()
{
	//This props wont work but whatever for now
	float highLimit = 0.05f;

	auto lastFrame = std::chrono::steady_clock::now();
	auto currentFrame = std::chrono::steady_clock::now();
	
	std::chrono::duration<float> delta = (currentFrame - lastFrame) / 1000.0f;
	float deltaTime = delta.count();
	lastFrame = currentFrame;

	if (deltaTime > highLimit)
	{
		deltaTime = highLimit;
	}
}

void WindowManager::ShutDown()
{
	SDL_DestroyWindow(window);
}