#pragma once

#include "RenderManager.h"

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif


RenderManager::RenderManager()
{
	renderer = nullptr;
	isRunning = false;
}

bool RenderManager::Initialize(SDL_Window* window)
{
	renderer = SDL_CreateRenderer(window, "SideScroller");

	if (!renderer)
	{
		SDL_Log("ERROR: Failed to initialize rendering engine: %s\n", SDL_GetError);
		return isRunning;
	}
	return isRunning = true;
}

void RenderManager::ShutDown()
{
	SDL_DestroyRenderer(renderer);
}