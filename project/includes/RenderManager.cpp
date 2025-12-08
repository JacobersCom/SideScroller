#pragma once
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif


#include "RenderManager.h"


//RenderManager& RenderManager::get()
//{
//	//This function-static will be constructed on the 
//	//first call to this function
//	static RenderManager sSingleton;
//	return sSingleton;
//}

RenderManager::RenderManager()
{
	renderer = nullptr;
	isRunning = true;
}

bool RenderManager::Initialize(SDL_Window* window)
{
	
	renderer = SDL_CreateRenderer(window, NULL);

	if (!renderer)
	{
		SDL_Log("ERROR: Failed to initialize rendering engine %s\n", SDL_GetError);
		return false;
	}

	return true;

}

void RenderManager::RenderLoop()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	//Clears the renderer with the current draw color
	SDL_RenderClear(renderer);

	//Updates the screen with any rendering performed since the last call
	SDL_RenderPresent(renderer);
}