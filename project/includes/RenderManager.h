#pragma once

#include "Defines.h"
#include "WindowManager.h"

class RenderManager 
{
public:

	bool Initialize(SDL_Window* window);
	RenderManager();
	~RenderManager();

	//Get the one and only instance
	static RenderManager& get();

private:

	SDL_Renderer* renderer;
	bool isRunning;
};