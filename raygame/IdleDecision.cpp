#include "IdleDecision.h"
#include "WanderBehavior.h"
#include "SeekBehaviour.h"
#include "Agent.h"

void IdleDecision::makeDecision(Agent* agent, float deltaTime)
{
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();

	if (wander)
		wander->setSteeringForce(0);

	SeekBehaviour* seek = agent->getComponent<SeekBehaviour>();

	if (seek)
		seek->setSteeringForce(0);
}
