#pragma once
#include "Component.h"
#include <Vector2.h>
class MovementComponent;
class Actor;

class SeekBehaviour :
	public Component
{
public:
	SeekBehaviour() : Component::Component() {}
	SeekBehaviour(Actor* agent, Actor* target, MovementComponent* moveComp);

	void update(float deltaTime) override;

private:
	MovementComponent* m_moveComponent;
	Actor* m_target;
	Actor* m_agent;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MathLibrary::Vector2 m_currentVelocity;
	float seekForce = 150;
};

