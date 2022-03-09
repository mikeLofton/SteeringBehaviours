#include "StartScene.h"
#include "Player.h"
#include "Sprite.h"
#include "MovementComponent.h"
#include "Transform2D.h"
#include "Enemy.h"
#include "SeekBehaviour.h"
#include "FleeBehavior.h"
#include "WanderBehavior.h"

void StartScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });

	Enemy* enemy = new Enemy(300, 50, "Enemy");
	enemy->getTransform()->setScale({ 50, 50 });
	enemy->setMaxForce(200);
	FleeBehavior* comp = new FleeBehavior();
	/*WanderBehavior* comp = new WanderBehavior(50, 3, 150);*/
	comp->setSteeringForce(150);
	comp->setTarget(player);

	enemy->addComponent(comp);

	addActor(player);
	addActor(enemy);
}
