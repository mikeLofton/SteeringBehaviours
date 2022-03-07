#pragma once
#include "SteeringBehaviors.h"
#include <Vector2.h>
class MovementComponent;
class Actor;

class SeekBehaviour :
	public SteeringBehaviors
{
public:
	SeekBehaviour() : SteeringBehaviors::SteeringBehaviors() {}
	SeekBehaviour(Actor* target, MovementComponent* moveComp);

	
	void update(float deltaTime) override;

	MathLibrary::Vector2 calculateForce() override;
private:
	MovementComponent* m_moveComponent;
	Actor* m_target;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MathLibrary::Vector2 m_currentVelocity;
	float seekForce = 150;
};

