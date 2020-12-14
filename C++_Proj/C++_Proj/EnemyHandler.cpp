#include "EnemyHandler.h"
#include <iostream>

EnemyHandler::EnemyHandler(int startX, int startY, int rows, int cols)
{
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
		Enemy* e = Enemy::get_instance(startX + i * 100, startY + j * 100, 60, 60);
		enemies.push_back(*e);
		gameSystem.add_sprites(e);
		}
	}
}
