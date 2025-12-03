#pragma once
class Actor
{
	//called every frame to update the actor
	virtual void Update(float deltaTime);
	//called every frame to draw the actor
	virtual void Draw();
};

