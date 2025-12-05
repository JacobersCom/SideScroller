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
	
	isRunning = true;
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

	auto lastFrame = std::chrono::steady_clock::now();
	auto currentFrame = std::chrono::steady_clock::now();
	
	std::chrono::duration<float> delta = (currentFrame - lastFrame);
	float deltaTime = delta.count();
	lastFrame = currentFrame;

	/*if (deltaTime > highLimit)
	{
		deltaTime = highLimit;
	}*/
}

void WindowManager::ShutDown()
{
	SDL_DestroyWindow(window);

	SDL_Quit();
}