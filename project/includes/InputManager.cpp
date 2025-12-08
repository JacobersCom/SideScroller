#pragma once

#include "InputManager.h"

InputManager::InputManager()
{
	keyState = SDL_GetKeyboardState(NULL);
	event = new SDL_Event;
}

InputManager::~InputManager()
{
	delete[] keyState;
	delete event;
}

void InputManager::ProcessInput(bool state)
{
	while (SDL_PollEvent(event))
	{
		switch (event->type)
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
	delete[] keyState;
	delete event;
}