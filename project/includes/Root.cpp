#include "Root.h"

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

Root::Root()
{
	isRunning = false;
	mWindowManager = nullptr;
	mRenderManager = nullptr;

}

bool Root::Initialize()
{
	mWindowManager = new WindowManager();
	mRenderManager = new RenderManager(); 

	mWindowManager->Initialize();
	mRenderManager->Initialize(mWindowManager->window);

	return isRunning = true;
}

void Root::GameLoop()
{
	while (isRunning)
	{
		mWindowManager->UpdateGame();
		mRenderManager->RenderLoop();
	}
}

void Root::ShutDown()
{
	mRenderManager->ShutDown();
	mWindowManager->ShutDown();
	
	delete mWindowManager;
	delete mRenderManager;

	SDL_Quit();
}