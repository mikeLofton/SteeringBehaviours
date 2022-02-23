#pragma once
#include "Component.h"
#include <Vector2.h>
class MovementComponent;

class WanderBehavior :
	public Component
{
public:
	WanderBehavior(const char* name = "Wander Behavior") : Component::Component(name) {}
	WanderBehavior(Actor* agent, Actor* target, MovementComponent* moveComp, const char* name = "WanderBehaviour");

	void update(float deltaTime) override;
private:
	float wanderRadius;
	float wanderDistance;
	Actor* wanderTarget;
};

