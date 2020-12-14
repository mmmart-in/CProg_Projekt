#pragma once
#include <vector>
#include "Enemy.h"
#include "GameSystem.h"
class EnemyHandler : public Sprite
{
public:
	//konstruktor kanske ska ta rows+columns som argument istället för att göra det lättare senare
	//vill man här bestämma width och height för hela raden? det går ju att göra.
	EnemyHandler(int startX, int startY, int rows, int cols);
	void tick();
	void draw();
private:
	int speed = 2;
	bool moveLeft = false;
	int enemyCount = 0;
	int tickCount = 0;
	Enemy* leftEnemy;
	Enemy* rightEnemy;
	void move();
	void outermost_enemies();
	void enemy_destroyed();
	std::vector<Enemy*> enemies;
};

