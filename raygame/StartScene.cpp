#include "StartScene.h"
#include "Player.h"
#include "Sprite.h"
#include "MovementComponent.h"
#include "Transform2D.h"
#include "Enemy.h"
#include "SeekBehaviour.h"
#include "FleeBehavior.h"
#include "WanderBehavior.h"
#include "StateMachine.h"

void StartScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });

	Enemy* enemy = new Enemy(300, 50, "Enemy");
	enemy->getTransform()->setScale({ 50, 50 });
	enemy->setMaxForce(200);

	SeekBehaviour* comp = new SeekBehaviour();
	comp->setSteeringForce(100);
	comp->setTarget(player);

	WanderBehavior* comp2 = new WanderBehavior(50, 3, 150);

	StateMachine* stateMachine = new StateMachine();

	enemy->addComponent(comp);
	enemy->addComponent(comp2);
	enemy->addComponent(stateMachine);

	addActor(player);
	addActor(enemy);
}
