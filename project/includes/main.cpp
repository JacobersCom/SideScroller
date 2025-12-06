#include "WindowManager.h"
#include "RenderManager.h"

int main()
{
	WindowManager wm;
	RenderManager rm;

	bool GameState = wm.Initialize();

	while (GameState)
	{
		wm.GameLoop();
	}

	wm.ShutDown();
}