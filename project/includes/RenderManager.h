#pragma once
#include "SDL3/SDL.h"


class RenderManager 
{
public:

	RenderManager();
	bool Initialize(SDL_Window* window);
	void RenderLoop();
	void ShutDown();

	//Get the one and only instance
	//static RenderManager& get();

private:

	SDL_Renderer* renderer;
	bool isRunning;
};