#pragma once

#include "SDL3/SDL.h"


class InputManager
{
public:
	
	InputManager();
	~InputManager();


	void ProcessInput(bool state);

	void ShutDown();


	SDL_Event* event;
	const bool* keyState = nullptr;
};