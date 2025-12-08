#pragma once

#include "SDL3/SDL.h"
#include <iostream>

class InputManager
{
public:
	
	InputManager();
	~InputManager();


	void ProcessInput(bool state);

	void ShutDown();


	const bool* keyState;
};