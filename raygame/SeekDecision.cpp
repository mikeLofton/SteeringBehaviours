#include "SeekDecision.h"
#include "SeekBehaviour.h"
#include "WanderBehavior.h"
#include "Agent.h"
#include "Enemy.h"

void SeekDecision::makeDecision(Agent* agent, float deltaTime)
{
	SeekBehaviour* seek = agent->getComponent<SeekBehaviour>();
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();
	Enemy* enemy = dynamic_cast<Enemy*>(agent);

	if (seek)
		seek->setSteeringForce(52);

	if (enemy)
		enemy->setIsAggressive(true);

	if (wander)
		wander->setSteeringForce(0);
}
