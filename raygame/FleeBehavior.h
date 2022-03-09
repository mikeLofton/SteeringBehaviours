#pragma once
#include "SeekBehaviour.h"
#include <Vector2.h>
class MovementComponent;

class FleeBehavior :
	public SeekBehaviour
{
public:
	MathLibrary::Vector2 calculateForce() override;
};

