#include "Enemy.h"
#include "Sprite.h"
#include "MovementComponent.h"
#include <raymath.h>
#include "Transform2D.h"

void Enemy::start()
{
	Actor::start();

	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/enemy.png")));
	m_moveComponent = addComponent<MovementComponent>();
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
	
	float posX = Clamp(getTransform()->getLocalPosition().x, 30, 650);
	float posY = Clamp(getTransform()->getLocalPosition().y, 30, 750);
	getTransform()->setLocalPosition(MathLibrary::Vector2(posX, posY));
}

void Enemy::draw()
{
	Actor::draw();

}

void Enemy::setForce(float value)
{
	m_force = value;
}

