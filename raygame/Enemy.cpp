#include "Enemy.h"
#include "SeekBehaviour.h"
#include "WanderBehavior.h"
#include "Sprite.h"
#include "Transform2D.h"
#include "AggressiveDecision.h"
#include "SeekDecision.h"
#include "WanderDecision.h"
#include "IdleDecision.h"
#include "InRangeDecision.h"
#include "DecisionComponent.h"
#include "raymath.h"

Enemy::Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target) : Agent(x, y, name, maxForce, maxSpeed)
{
	m_target = target;
}

void Enemy::start()
{
	Agent::start();

	IdleDecision* idle = new IdleDecision();
	WanderDecision* wander = new WanderDecision();
	SeekDecision* seek = new SeekDecision();

	AggressiveDecision* aggressive = new AggressiveDecision(idle, wander);
	InRangeDecision* inRange = new InRangeDecision(aggressive, seek);

	addComponent(new DecisionComponent(inRange));

	getTransform()->setScale({ 50, 50 });
	addComponent(new Sprite("Images/enemy.png"));

	WanderBehavior* wanderComp = new WanderBehavior(1000, 100, 100);
	addComponent(wanderComp);

	SeekBehaviour* seekComp = new SeekBehaviour();
	seekComp->setSteeringForce(50);
	seekComp->setTarget(m_target);
	addComponent(seekComp);
}

bool Enemy::getTargetInRange()
{
	float distance = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
	
	if (getTargetInSight() && distance <= 300)
		return true;

	return false;
}

bool Enemy::getTargetInSight()
{
	MathLibrary::Vector2 directionOfTarget = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getNormalized();
	return RAYMATH_H::acos( MathLibrary::Vector2::dotProduct(directionOfTarget, getTransform()->getForward())) * (180 / PI) < 30;
}
