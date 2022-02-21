#include "Enemy.h"
#include "Sprite.h"

void Enemy::start()
{
	Actor::start();

	m_spriteComponent = dynamic_cast<Sprite*>(addComponent(new Sprite("Images/enemy.png")));
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
