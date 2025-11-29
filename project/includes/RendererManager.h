#pragma once

#include "Defines.h"
#include "WindowManager.h"

class RendererManager : public WindowManager
{
	bool Initialize();

private:

	SDL_Renderer* renderer;
	bool isRunning;
};