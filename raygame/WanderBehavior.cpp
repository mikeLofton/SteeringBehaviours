#include "WanderBehavior.h"
#include "Transform2D.h"
#include "Enemy.h"
#include "MovementComponent.h"
#include <time.h>

WanderBehavior::WanderBehavior(float circleDistance, float circleRadius, float wanderForce) : SteeringBehaviors(nullptr, wanderForce)
{
	m_circleDistance = circleDistance;
	m_circleRadius = circleRadius;
	srand(time(NULL));
}

MathLibrary::Vector2 WanderBehavior::calculateForce()
{
	if (getSteeringForce() == 0)
		return { 0,0 };

	//Find the agent's position and heading
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 heading = getAgent()->getMoveComponent()->getVelocity().getNormalized();

	//Foound the circle's position in front of the agent
	m_circlePosition = ownerPosition + (heading * m_circleDistance);

	//Find a random vector in the circle
	float randNum1 = (rand() % 201) - 100;
	float randNum2 = (rand() % 201) - 100;
	MathLibrary::Vector2 randDirection = MathLibrary::Vector2{ randNum1, randNum2 }.normalize() * m_circleRadius;

	//Add the random vector to the circle position to get a new random point on the circle
	m_target = randDirection + m_circlePosition;

	//Seek to the random point
	MathLibrary::Vector2 desiredVelocity = MathLibrary::Vector2::normalize(m_target - ownerPosition) * getSteeringForce();
	MathLibrary::Vector2 force = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return force;
}
