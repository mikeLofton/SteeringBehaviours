#include "WanderDecision.h"
#include "WanderBehavior.h"
#include "SeekBehaviour.h"
#include "Agent.h"

void WanderDecision::makeDecision(Agent* agent, float deltaTime)
{
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();
	SeekBehaviour* seek = agent->getComponent<SeekBehaviour>();

	if (wander)
		wander->setSteeringForce(52);

	if (seek)
		seek->setSteeringForce(0);
}
