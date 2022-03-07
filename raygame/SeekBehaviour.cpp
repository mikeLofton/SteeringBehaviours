#include "SeekBehaviour.h"
#include "Transform2D.h"
#include "Actor.h"
#include "MovementComponent.h"

SeekBehaviour::SeekBehaviour(Actor* target, MovementComponent* moveComp) : SteeringBehaviors::SteeringBehaviors()
{
	m_target = target;
	m_moveComponent = moveComp;
}

void SeekBehaviour::update(float deltaTime)
{
	m_currentVelocity = m_moveComponent->getVelocity();
	m_desiredVelocity = MathLibrary::Vector2::normalize(m_target->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()) * seekForce;
	m_steeringForce = m_desiredVelocity - m_currentVelocity;
	m_moveComponent->setVelocity(m_moveComponent->getVelocity() + (m_steeringForce * deltaTime));
	getOwner()->getTransform()->setWorldPostion(getOwner()->getTransform()->getWorldPosition() + (m_moveComponent->getVelocity() * deltaTime));

	getOwner()->getTransform()->setForward(MathLibrary::Vector2::normalize(m_moveComponent->getVelocity()));
}

MathLibrary::Vector2 SeekBehaviour::calculateForce()
{
	if (!getTarget())
		return { 0,0 };

	MathLibrary::Vector2 directionToTarget = getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition();
	
	return MathLibrary::Vector2();
}
