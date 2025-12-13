#pragma

#include "Actor.h"

class Component
{
public:

	/*
	Constructor
	The lower the update order the earlier the component will update
	*/

	Component(class Actor* owner, int updateOrder = 100);

	virtual ~Component();

	// Update this component by deltaTime
	virtual void Update(float deltaTime);

	int GetUpdateOrder() const { return mUpdateOrder; }

protected:

	//owning actor

	class Actor* mOwner;

	//Upated order of component

	int mUpdateOrder;
};