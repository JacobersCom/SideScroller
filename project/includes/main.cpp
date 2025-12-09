#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "Root.h"



int main()
{
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Root r;

	bool GameState = r.Initialize();

	while (GameState)
	{
		r.GameLoop();
	}

	r.ShutDown();

}