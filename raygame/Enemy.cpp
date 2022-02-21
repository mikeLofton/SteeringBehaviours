#include "Enemy.h"
#include "Sprite.h"
#include "SeekBehaviour.h"
#include "MovementComponent.h"

void Enemy::start()
{
	Actor::start();

	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/enemy.png")));
	m_moveComponent = dynamic_cast<MovementComponent*>(addComponent(new MovementComponent()));
	m_seekBehaviour = dynamic_cast<SeekBehaviour*>(addComponent(new SeekBehaviour(this, m_target, m_moveComponent)));
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);
	
}

void Enemy::draw()
{
	Actor::draw();

}

void Enemy::onCollision(Actor* other)
{
}
