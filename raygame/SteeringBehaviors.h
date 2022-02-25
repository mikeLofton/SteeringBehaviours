#pragma once
#include "Component.h"
#include <Vector2.h>
class SteeringBehaviors :
	public Component
{
public:
	SteeringBehaviors() : Component::Component() {}
	SteeringBehaviors(Actor* target);

	void update(float deltaTime) override;
	MathLibrary::Vector2 calculateForce();

private:
	MathLibrary::Vector2 m_force;
	Actor* m_target;
};

