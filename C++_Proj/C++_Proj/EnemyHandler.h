#pragma once
#include <vector>
#include "Enemy.h"
#include "GameSystem.h"
class EnemyHandler : public Sprite
{
public:
	//konstruktor kanske ska ta rows+columns som argument ist�llet f�r att g�ra det l�ttare senare
	//vill man h�r best�mma width och height f�r hela raden? det g�r ju att g�ra.
	EnemyHandler(int startX, int startY, int rows, int cols);
	void tick();
	void draw();
private:
	Enemy* leftEnemy;
	Enemy* rightEnemy;
	void move();
	void outermost_enemies();
	std::vector<Enemy*> enemies;
};

