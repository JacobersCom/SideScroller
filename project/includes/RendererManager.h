#pragma once

#include "Defines.h"
#include "WindowManager.h"

class RendererManager 
{
	bool Initialize(SDL_Window* window);

private:

	SDL_Renderer* renderer;
	bool isRunning;
};