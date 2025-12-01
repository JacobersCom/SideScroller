#include "WindowManager.h"


int main()
{
	WindowManager wm;

	bool GameState = wm.Initialize();

	while (GameState == true)
	{
		
	}

	wm.ShutDown();
}