#include "Root.h"

Root::Root()
{
	isRunning = true;
	mWindowManager = nullptr;
	mRenderManager = nullptr;

}

Root::~Root()
{
	delete mWindowManager;
	delete mRenderManager;
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
}