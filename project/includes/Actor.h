#pragma once

#include "Defines.h"

#include <vector>

class Actor
{
public:
	//used to track state of actor
	enum State
	{
		EActive,
		EPaused,
		EDead,
	};

	//Contructor/destructor
	Actor(class Root* game);

	virtual ~Actor();

	//Update function called from game (not overridable)
	void Update(float deltaTime);

	//Updates all components attached to actor (not overridable)

	void UpdateComponents(float deltaTime);

	// Any actor-specific update code (overridable)
	virtual void UpdateActor(float deltaTime);


	//Getter/Setter

	//Add/remove components

	void AddComponent(class Component* comp);
	void RemoveComponent(class Component* comp);

private:

	State mState;

	vec2 mPosition; // Center of actor

	float mScale;	//Scale of actor 1.0 for 100%
	float mRotation; // Angle in radians

	std::vector<class Component*> mComponents;

	Root* mGame;

};