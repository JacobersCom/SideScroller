#include "Root.h"

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

Root::Root()
{
	isRunning = true;
	mWindowManager = nullptr;
	mRenderManager = nullptr;

}

bool Root::initalize()
{
	mWindowManager = new WindowManager();
	mRenderManager = new RenderManager(); 

	mWindowManager->Initialize();
	mRenderManager->Initialize(mWindowManager->window);

	return true;
}

void Root::GameLoop()
{
	while (isRunning)
	{
		mWindowManager->UpdateGame();
	}
}

void Root::ShutDown()
{


	mWindowManager->ShutDown();

	delete mWindowManager;
	delete mRenderManager;
}