#include "EnemyHandler.h"
#include <iostream>

EnemyHandler::EnemyHandler(int startX, int startY, int rows, int cols) : Sprite(1, 1, 1, 1, "Ingen image")
{	
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
		Enemy* e = Enemy::get_instance(startX + i * 100, startY + j * 100, 60, 60, i, j);
		enemies.push_back(e);
		enemyCount++;
		}
	}
	//varning om oinitialiserade variabler sköts här
	outermost_enemies();
}

void EnemyHandler::tick()
{
	tickCount++;
	for (Enemy* e : enemies) 
	{
		e->tick();
	}
	if (tickCount  %  enemyCount== 0) 
	{
		move();
	}
}

void EnemyHandler::draw() 
{
	for (Enemy* e : enemies) {
		e->draw();
	}
}
void EnemyHandler::move() 
{
	for (Enemy* e : enemies)
		e->move_right();


	//slog LEFT_ENEMY i väggen? 
	//byt håll
}


void EnemyHandler::outermost_enemies()
{
	//magic number borde vara MAX_NUM_OF_ENEMIES typ

	for (Enemy* e : enemies) {
		if (leftEnemy != NULL && rightEnemy != NULL) {
			if (e->col < leftEnemy->col)
				leftEnemy = e;

			if (e->col > rightEnemy->col)
				rightEnemy = e;
		}
		else {
			leftEnemy = e;
			rightEnemy = e;
		}
	}


}
void  EnemyHandler::enemy_destroyed() {
	//förutsatt att denna metod BARA kallas när en fiende dör
	enemyCount--;
}
//enemydestroyed, uppdatera fiender längst ut på kanten (kalla på outermost_enemies();)