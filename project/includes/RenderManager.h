#pragma once
#include "SDL3/SDL.h"


class RenderManager 
{
public:

	RenderManager();
	
	bool Initialize(SDL_Window* window);
	void ShutDown();

private:

	SDL_Renderer* renderer;
	bool isRunning;
};