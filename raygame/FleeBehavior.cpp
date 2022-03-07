#include "FleeBehavior.h"
#include "Transform2D.h"
#include "Actor.h"
#include "MovementComponent.h"

FleeBehavior::FleeBehavior(Actor* target, MovementComponent* moveComp) : Component::Component()
{
	m_target = target;
	m_moveComponent = moveComp;
}

void FleeBehavior::update(float deltaTime)
{
	m_currentVelocity = m_moveComponent->getVelocity();
	m_desiredVelocity = MathLibrary::Vector2::normalize(getOwner()->getTransform()->getWorldPosition() - m_target->getTransform()->getWorldPosition()) * fleeForce;
	m_steeringForce = m_desiredVelocity - m_currentVelocity;
	m_moveComponent->setVelocity(m_moveComponent->getVelocity() + (m_steeringForce * deltaTime));
	getOwner()->getTransform()->setWorldPostion(getOwner()->getTransform()->getWorldPosition() + (m_moveComponent->getVelocity() * deltaTime));

	getOwner()->getTransform()->setForward(MathLibrary::Vector2::normalize(m_moveComponent->getVelocity()));
}
