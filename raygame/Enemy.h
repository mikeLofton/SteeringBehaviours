#pragma once
#include "Actor.h"
class MovementComponent;
class Sprite;
class SeekBehaviour;

class Enemy :
	public Actor
{
public:
	Enemy(float x, float y, const char* name, Actor* target) : Actor(x, y, name)
	{
		m_target = target;
		m_moveComponent = nullptr;
		m_spriteComponent = nullptr;
	}

	~Enemy()
	{
		m_target = nullptr;
		m_moveComponent = nullptr;
		m_spriteComponent = nullptr;
	}

	void start() override;
	void update(float deltaTime) override;
	void draw() override;
	void onCollision(Actor* other) override;

private:
	MovementComponent* m_moveComponent;
	Sprite* m_spriteComponent;
	SeekBehaviour* m_seekBehaviour;
	Actor* m_target;
};

