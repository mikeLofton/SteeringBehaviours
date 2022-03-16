#include "StartScene.h"
#include "Player.h"
#include "Sprite.h"
#include "MovementComponent.h"
#include "Transform2D.h"
#include "StateMachine.h"
#include "Enemy.h"

void StartScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });

	Enemy* enemy = new Enemy(300, 50, "Enemy", 100, 200, player);

	addActor(player);
	addActor(enemy);
}
