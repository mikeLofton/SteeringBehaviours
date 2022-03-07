#include "SteeringBehaviors.h"

SteeringBehaviors::SteeringBehaviors(Actor* target, float steeringForce) : Component::Component() 
{
	m_target = target;
	m_steeringForce = steeringForce;
}
