#include "EnemyHandler.h"
#include <iostream>


EnemyHandler::EnemyHandler(int startX, int startY, int rows, int cols) : Sprite(1, 1, 1, 1)
{	
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
		Enemy* e = Enemy::get_instance(startX + i * COL_WIDTH, startY + j * ROW_HEIGHT, 60, 60, i, j);
		enemies.push_back(e);
		enemyCount++;
		}
	}
	//varning om oinitialiserade variabler sköts här
	outermost_enemies();
}

EnemyHandler* EnemyHandler::create_instance(int startX, int startY, int rows, int cols) {
	return new EnemyHandler(startX, startY, rows, cols);
}

void EnemyHandler::tick()
{
	tickCount++;
	for (Enemy* e : enemies) 
	{
		e->tick();
	}
	if (SDL_GetTicks()  %  enemyCount / speed == 0) 
	{
		move();
	}
}
void EnemyHandler::move_down() 
{
	for (Enemy* e : enemies)
		e->rect.y += ROW_HEIGHT;
}
void EnemyHandler::draw() 
{
	for (Enemy* e : enemies) {
		e->draw();
	}
}
void EnemyHandler::move() 
{
	if (leftEnemy->rect.x <= 5) {
		moveLeft = false;
		move_down();
		std::cout << "moveleft false";
	}
	else if (!moveLeft && rightEnemy->rect.x > 1200 - rightEnemy->rect.w) {
		moveLeft = true;
		move_down();
	}
	

	for (Enemy* e : enemies)
	{
		e->move(moveLeft);
	}

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