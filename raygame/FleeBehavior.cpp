#include "FleeBehavior.h"
#include "Transform2D.h"
#include "Actor.h"
#include "MovementComponent.h"
#include "Enemy.h"

MathLibrary::Vector2 FleeBehavior::calculateForce()
{
	if (!getTarget())
		return { 0,0 };

	MathLibrary::Vector2 directionToTarget = getOwner()->getTransform()->getWorldPosition() - getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
	MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return seekForce;
}
