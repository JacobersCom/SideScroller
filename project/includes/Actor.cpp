#include "Actor.h"

Actor::Actor(Root* game): mState(EActive), mRotation(1.0f), mScale(1.0f), mRoot(game)
{
	this->mRoot = game;
	this->mState = State::EActive; // The actor is active
	this->mPosition = { 0.0f, 0.0f };
	this->mRotation = 0.0f;
	this->mScale = 1.0f;

	mRoot->AddActor(this); // add this actor to the game
}

Actor::~Actor()
{
	//Remove this actor and while the component list is not empty delete any components in the list
	mRoot->RemoveActor(this);
	while (!this->mComponents.empty())
	{
		delete this->mComponents.back();
	}
}

void Actor::Update(float deltaTime)
{
	while (State::EActive)
	{
		this->UpdateComponents(deltaTime);
		this->UpdateActor(deltaTime);
	}
}

void Actor::UpdateComponents(float deltaTime)
{
	for (auto c : mComponents)
	{
		c->Update(deltaTime); // Update the componets
	}
}

void Actor::UpdateActor(float deltaTime)
{

}

void Actor::AddComponent(Component* comp)
{
	auto iter = this->mComponents.begin();
	for (; iter != mComponents.end(); ++iter)
	{
		if (comp->GetUpdateOrder() < (*iter)->GetUpdateOrder())
		break;
	}
	this->mComponents.insert(iter, comp); // inserts the comp at the iter
}

void Actor::RemoveComponent(Component* comp)
{
	//Find this comp in the list of comps
	auto iter = std::remove(this->mComponents.begin(), this->mComponents.end(), comp);
	//Remove this comp and make it the new end of the list
	this->mComponents.erase(iter, mComponents.end());
}
