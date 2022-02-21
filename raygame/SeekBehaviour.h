#pragma once
#include "Component.h"
#include <Vector2.h>
class MovementComponent;
class Actor;

class SeekBehaviour :
	public Component
{
public:
	SeekBehaviour(const char* name = "SeekBehaviour") : Component::Component(name) {}

	void update(float deltaTime) override;

private:
	MovementComponent* m_moveComponent;
	Actor* m_target;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_steeringForce;
};

