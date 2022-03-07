#pragma once
#include "Component.h"
#include <Vector2.h>
class MovementComponent;

class WanderBehavior :
	public Component
{
public:
	WanderBehavior() : Component::Component() {}
	WanderBehavior(Actor* target, MovementComponent* moveComp);

	void update(float deltaTime) override;
private:
	float wanderRadius;
	float wanderDistance;
	float m_force;
	Actor* wanderTarget;
};

