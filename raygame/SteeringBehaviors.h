#pragma once
#include "Component.h"
#include <Vector2.h>
class MovementComponent;
class Agent;

class SteeringBehaviors :
	public Component
{
public:
	SteeringBehaviors() : Component::Component() { m_target = nullptr; m_steeringForce = 0; }

	/// <summary>
	/// Initializes the target
	/// </summary>
	SteeringBehaviors(Actor* target, float steeringForce);

	/// <summary>
	/// Must be overriden by inherited classes. 
	/// Place the logic for steering behavior here.
	/// </summary>
	/// <returns></returns>
	virtual MathLibrary::Vector2 calculateForce() = 0;

	/// <summary>
	/// Returns the target
	/// </summary>
	Actor* getTarget() { return m_target; }

	/// <summary>
	/// Sets the target actor
	/// </summary>
	void setTarget(Actor* target) { m_target = target; }

	float getSteeringForce() { return m_steeringForce; }
	void setSteeringForce(float value) { m_steeringForce = value; }

	Agent* getAgent() { return (Agent*)getOwner(); }

private:
	float m_steeringForce = 0;
	Actor* m_target = nullptr;
	MovementComponent* m_moveComponent;
};

