#pragma once
#include "Component.h"
#include <Vector2.h>

class MovementComponent :
    public Component
{
public:
    MovementComponent() : Component::Component() {}

    /// <summary>
    /// Get the current speed and direction of this actor
    /// </summary>
    /// <returns></returns>
    MathLibrary::Vector2 getVelocity() { return m_velocity; }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="velocity"></param>
    void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }
    
    /// <summary>
    /// Get the maximum magnitude of this actors velocity vector
    /// </summary>
    /// <returns></returns>
    float getMaxSpeed() { return m_maxSpeed; }

    /// <summary>
    /// Set the maximum magnitude of this actors velocity vector
    /// </summary>
    /// <param name="maxSpeed"></param>
    void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }

    bool getUpdateFacing() { return m_updateFacing; }
    void setUpdateFacing(bool value) { m_updateFacing = value; }

    //Inherited from component class
    void update(float deltaTime) override;
private:
    MathLibrary::Vector2 m_velocity;
    float m_maxSpeed;
    bool m_updateFacing;
};

