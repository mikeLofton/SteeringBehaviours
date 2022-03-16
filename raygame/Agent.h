#pragma once
#include "Actor.h"
#include "ActorArray.h"
#include <Vector2.h>
#include"MovementComponent.h"
class Sprite;
class SteeringBehaviors;

class Agent :
	public Actor
{
public:
	Agent(float x, float y, const char* name, float maxForce, float maxSpeed) : Actor(x, y, name)
	{
		setMaxForce(maxForce);
		m_moveComponent = addComponent<MovementComponent>();
		m_moveComponent->setMaxSpeed(maxSpeed);
		m_spriteComponent = nullptr;

	}

	~Agent()
	{
		m_moveComponent = nullptr;
		m_spriteComponent = nullptr;
	}

	void start() override;
	void update(float deltaTime) override;
	void draw() override;

	/// <summary>
	/// Used to add new steering components to the steering components array
	/// </summary>
	/// <param name="comp"></param>
	void onAddComponent(Component* comp) override;

	/// <summary>
	/// Returns the force currently being applied to the enemy
	/// </summary>
	MathLibrary::Vector2 getForce() { return m_force; }

	/// <summary>
	/// Applies the given force to the enemy
	/// </summary>
	/// <param name="value">The given force</param>
	void setForce(MathLibrary::Vector2 value) { m_force = value; }

	float getMaxForce() { return m_maxForce; }
	void setMaxForce(float value) { m_maxForce = value; }
	MovementComponent* getMoveComponent() { return m_moveComponent; }

private:
	DynamicArray<SteeringBehaviors*> m_steeringBehaviors; //Array containing all steering components attached to the enemy
	MovementComponent* m_moveComponent;
	Sprite* m_spriteComponent;
	float m_maxForce;
	MathLibrary::Vector2 m_force;
};

