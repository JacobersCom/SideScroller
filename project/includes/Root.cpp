#include "Root.h"

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

Root::Root()
{
	GameState = false;
	mWindowManager = nullptr;
	mRenderManager = nullptr;
	mInputManager = nullptr;

}

bool Root::Initialize()
{
	mWindowManager = new WindowManager();
	mRenderManager = new RenderManager(); 
	mInputManager = new InputManager();

	mWindowManager->Initialize();
	mRenderManager->Initialize(mWindowManager->window);

	return GameState = true;
}

void Root::GameLoop()
{
	while (GameState)
	{
		mWindowManager->UpdateGame();
		mRenderManager->RenderLoop();
		mInputManager->ProcessInput(GameState);
	}
}

void Root::ShutDown()
{
	mRenderManager->ShutDown();
	mWindowManager->ShutDown();

	SDL_Quit();
}

Root::~Root()
{
	delete mRenderManager;
	delete mWindowManager;
	delete mInputManager;
}