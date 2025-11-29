#pragma once

#include "RendererManager.h"

RendererManager::RendererManager()
{
	renderer = nullptr;
	isRunning = false;
}

bool RendererManager::Initialize()
{
	renderer = SDL_CreateRenderer(window, "sidescroller");

	if (!renderer)
	{
		SDL_Log("ERROR: Failed to initialize rendering engine: %s\n", SDL_GetError);
		return false;
	}

	return true;

}