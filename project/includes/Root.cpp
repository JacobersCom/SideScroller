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
		
		UpdateActor();
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

void Root::AddActor(Actor* _Actor)
{
	//if updating actors add to pending
	if (UpdatingActors)
	{
		mPendingActors.emplace_back(_Actor);
	}
	else
	{
		mActors.emplace_back(_Actor);
	}
}
//TO-DO (Rework function logic)
void Root::RemoveActor(Actor* _Actor)
{
	// if updating actors remove from pending
	if (UpdatingActors) 
	{	
		//Find the actor within mPendingActors
		auto it = std::remove(mPendingActors.begin(),
			mPendingActors.end(), _Actor);
		
		//KILL IT
		mPendingActors.erase(it, mPendingActors.end());
	}
	else
	{
		//Find the actor within mActors
		auto it = std::remove(mActors.begin(),
			mActors.end(), _Actor);

		//KILL IT
		mActors.erase(it, mActors.end());
	}
}

void Root::UpdateActor()
{
	UpdatingActors = true;

	//Update all actors
	for (auto actor : mActors)
	{
		actor->Update(mWindowManager->deltaTime);
	}

	UpdatingActors = false;

	for (auto pending : mPendingActors)
	{
		mActors.emplace_back(pending);
	}

	//Clear out all pending actors after moving them to mActors
	mPendingActors.clear();

	//Add "dead" actors to a temp vec
	std::vector<Actor*> deadActor;
	for (auto actor : mActors)
	{
		if (actor->EDead)
		{
			deadActor.emplace_back(actor);
		}
	}

	//Delete dead Actors which will remove them from mActors

	for (auto actor : deadActor)
	{
		delete actor;
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

	while (!mActors.empty())
	{
		delete mActors.back();
	}
}