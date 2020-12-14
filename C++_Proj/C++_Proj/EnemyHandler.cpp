#include "EnemyHandler.h"
#include <iostream>

EnemyHandler::EnemyHandler(int startX, int startY, int rows, int cols) : Sprite(1, 1, 1, 1, "Ingen image")
{	
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
		Enemy* e = Enemy::get_instance(startX + i * 100, startY + j * 100, 60, 60);
		enemies.push_back(e);
		}
	}
}

void EnemyHandler::tick()
{
	for (Enemy* e : enemies) 
	{
		e->tick();
	}
}

void EnemyHandler::draw() 
{
	for (Enemy* e : enemies) {
		e->draw();
		std::cout << "enemyhandler draw";
	}
}