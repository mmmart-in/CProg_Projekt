#include "EnemyHandler.h"
#include <iostream>

EnemyHandler::EnemyHandler(int startX, int startY, int numOfEnemies) : x(startX), y(startY)
{
	for (int i = 0; i < numOfEnemies; i++) {
		Enemy* e = Enemy::get_instance(startX + i*100, startY, 60, 60);
		std::cout << "enemy skapad" << i;
		gameSystem.add_sprites(e);
	}
}
