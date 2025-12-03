#include "WindowManager.h""

WindowManager::WindowManager()
{
	window = nullptr;
	isRunning = false;

	lastFrame = std::chrono::duration<floa>
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

void WindowManager::GameLoop()
{
	while (isRunning)
	{
		UpdateGame();
	}
}


void WindowManager::UpdateGame()
{
	constexpr std::chrono::duration<float> highLimit(0.5f);

	auto currentFrame = std::chrono::steady_clock::now();
	
	auto deltaTime = std::chrono::duration<float>(currentFrame - lastFrame) / 1000.0f;
	lastFrame = currentFrame;

	if (deltaTime > highLimit)
	{
		deltaTime = highLimit;
	}
}

void WindowManager::ShutDown()
{
	SDL_DestroyWindow(window);

	SDL_Quit();
}