#pragma once
#include <vector>
#include "Enemy.h"
#include "GameSystem.h"
class EnemyHandler
{
public:
	//konstruktor kanske ska ta rows+columns som argument istället för att göra det lättare senare
	//vill man här bestämma width och height för hela raden? det går ju att göra.
	EnemyHandler(int startX, int startY, int rows, int cols);
private:
	std::vector<Enemy> enemies;
};

