#include "Actor.h"

Actor::Actor(Root* game): mState(EActive), mRotation(1.0f), mScale(1.0f), mRoot(game)
{
	game->AddActor(this);
}

Actor::~Actor()
{
	mRoot->RemoveActor(this);
}

void Actor::Update(float deltaTime)
{

}

void Actor::UpdateComponents(float deltaTime)
{

}

void Actor::UpdateActor(float deltaTime)
{
}

void Actor::AddComponent(Component* comp)
{
}

void Actor::RemoveComponent(Component* comp)
{
}
