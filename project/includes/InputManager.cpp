#pragma once

#include "InputManager.h"

InputManager::InputManager()
{
	keyState = SDL_GetKeyboardState(NULL);
	
}

InputManager::~InputManager()
{
	
}

void InputManager::ProcessInput(bool state)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

			case SDL_EVENT_QUIT:
			{
				state = false;
				break;
			}
			
		}
	}
}

void InputManager::ShutDown()
{
	
}