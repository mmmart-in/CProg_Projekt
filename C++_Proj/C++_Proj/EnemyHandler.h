#pragma once
#include <vector>
#include "Enemy.h"
#include "GameSystem.h"

#define ROW_HEIGHT 60
#define COL_WIDTH 80

class EnemyHandler : public Sprite
{
public:
	//konstruktor kanske ska ta rows+columns som argument ist�llet f�r att g�ra det l�ttare senare
	//vill man h�r best�mma width och height f�r hela raden? det g�r ju att g�ra.
	static EnemyHandler* create_instance(int, int, int, int);
	void tick();
	void draw();
private:
	EnemyHandler(int startX, int startY, int rows, int cols);
	int speed = 2;
	bool moveLeft = false;
	int enemyCount = 0;
	int tickCount = 0;
	Enemy* leftEnemy;
	Enemy* rightEnemy;
	void move();
	void outermost_enemies();
	void enemy_destroyed();
	void move_down();
	std::vector<Enemy*> enemies;
};

