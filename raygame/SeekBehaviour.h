#pragma once
#include "SteeringBehaviors.h"
#include <Vector2.h>
class MovementComponent;
class Actor;

class SeekBehaviour :
	public SteeringBehaviors
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

