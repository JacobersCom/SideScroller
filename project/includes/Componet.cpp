#include "Componet.h"

Component::Component(Actor* owner, int updateOrder)
{
	this->mOwner = owner; //The actor owns this component
	this->mUpdateOrder = mUpdateOrder; //This component will be updated in this order
	this->mOwner->AddComponent(this); //Add this component to this actor
}

Component::~Component()
{
	delete mOwner;
}
