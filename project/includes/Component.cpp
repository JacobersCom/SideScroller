#include "Actor.h"
#include "Component.h"
#include "Actor.h"

Component::Component(class Actor* owner, int updateOrder)
{
	this->mOwner = owner; //The actor owns this component
	this->mUpdateOrder = updateOrder; //This component will be updated in this order
	this->mOwner->AddComponent(this); //Add this component to this actor
}

Component::~Component()
{
	this->mOwner->RemoveComponent(this);
}

void Component::Update(float deltaTime)
{
	
}
