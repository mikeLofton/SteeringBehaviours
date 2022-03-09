#include "StateMachine.h"
#include "SeekBehaviour.h"
#include "WanderBehavior.h"
#include "Actor.h"
#include "Transform2D.h"

void StateMachine::start()
{
	Component::start();

	m_seekComponent = getOwner()->getComponent<SeekBehaviour>();
	m_seekForce = m_seekComponent->getSteeringForce();

	m_wanderComponent = getOwner()->getComponent<WanderBehavior>();
	m_wanderForce = m_wanderComponent->getSteeringForce();

	m_currentState = IDLE;
}

void StateMachine::update(float deltaTime)
{
	MathLibrary::Vector2 targetPos = m_seekComponent->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();
	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();

	bool targetInRange = distanceFromTarget <= m_seekRange;

	switch (m_currentState)
	{
	case IDLE:
		m_seekComponent->setSteeringForce(0);
		m_wanderComponent->setSteeringForce(0);

		if (targetInRange)
			setCurrentState(SEEK);

		break;
	case WANDER:
		m_seekComponent->setSteeringForce(0);
		m_wanderComponent->setSteeringForce(m_wanderForce);

		if (targetInRange)
			setCurrentState(SEEK);

		break;
	case SEEK:
		m_seekComponent->setSteeringForce(m_seekForce);
		m_wanderComponent->setSteeringForce(0);

		if (!targetInRange)
			setCurrentState(WANDER);

		break;
	}
}
