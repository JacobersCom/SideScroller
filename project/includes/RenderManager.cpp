#pragma once

#include "RenderManager.h"


RenderManager& RenderManager::get()
{
	//This function-static will be constructed on the 
	//first call to this function
	static RenderManager sSingleton;
	return sSingleton;
}

RenderManager::RenderManager()
{
	
	renderer = nullptr;
	isRunning = false;
}

RenderManager::~RenderManager()
{
}

bool RenderManager::Initialize(SDL_Window* window)
{
	//Start up other managers we depend on
	//by using their get functions

	renderer = SDL_CreateRenderer(window, "sidescroller");

	if (!renderer)
	{
		SDL_Log("ERROR: Failed to initialize rendering engine: %s\n", SDL_GetError);
		return false;
	}

	return true;

}