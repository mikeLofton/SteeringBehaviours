#pragma once
#include "Actor.h"
#include "ActorArray.h"
class MovementComponent;
class Sprite;
class SteeringBehaviors;

class Enemy :
	public Actor
{
public:
	Enemy(float x, float y, const char* name) : Actor(x, y, name)
	{
		m_moveComponent = nullptr;
		m_spriteComponent = nullptr;
	}

	~Enemy()
	{
		m_moveComponent = nullptr;
		m_spriteComponent = nullptr;
	}

	void start() override;
	void update(float deltaTime) override;
	void draw() override;
	void onAddComponent(Component* comp) override;
	float getForce() { return m_force; }
	void setForce(float value);

private:
	DynamicArray<SteeringBehaviors*> m_steeringBehaviors;
	MovementComponent* m_moveComponent;
	Sprite* m_spriteComponent;
	float m_maxForce;
	float m_maxVelocity;
	float m_force;
};

