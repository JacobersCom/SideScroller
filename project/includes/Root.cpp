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

/*
		using emplace_back instead of push_back
		because instead of creating a temp object
		and then a copie, I can just construct the Actor
		directly in-place within the vector's memory,
		because Actor is a complex object, if it wasn't 
		I'd use push_back.
*/

void Root::AddActor(Actor* Actor)
{
	//if updating actors add to pending
	if (UpdatingActors)
	{
		mPendingActors.emplace_back(Actor);
	}
	else
	{
		mActors.emplace_back(Actor);
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