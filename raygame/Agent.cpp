#include "Agent.h"
#include "Sprite.h"
#include "MovementComponent.h"
#include <raymath.h>
#include "Transform2D.h"
#include "SteeringBehaviors.h"

void Agent::start()
{
	Actor::start();

	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/enemy.png")));
	
	m_moveComponent->setUpdateFacing(true);
}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);

	//Get all force being applied from the steering behaviors 
	for (int i = 0; i < m_steeringBehaviors.getLength(); i++)
	{
		m_force = m_force + m_steeringBehaviors[i]->calculateForce();
	}

	//Clamp force if it exceeds the maximum scale
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}

	//Apply force to velocity
	getMoveComponent()->setVelocity(getMoveComponent()->getVelocity() + m_force * deltaTime);
}

void Agent::draw()
{
	Actor::draw();
}

void Agent::onAddComponent(Component* comp)
{
	SteeringBehaviors* steeringComponent = dynamic_cast<SteeringBehaviors*>(comp);

	if (steeringComponent)
		m_steeringBehaviors.addItem(steeringComponent);
}


