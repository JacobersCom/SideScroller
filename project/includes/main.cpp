#include "Root.h"

int main()
{
	Root r;

	bool GameState = r.initalize();

	while (GameState)
	{
		r.GameLoop();
	}

	r.ShutDown();
}