#pragma once
#include "SDL3/SDL.h"
#include <iostream>

class RenderManager 
{
public:

	RenderManager();
	~RenderManager();

	bool Initialize(SDL_Window* window);
	void RenderLoop();
	void DrawBackGround();
	void ShutDown();

	//Get the one and only instance
	//static RenderManager& get();

	SDL_Renderer* renderer;
	bool isRunning;
};