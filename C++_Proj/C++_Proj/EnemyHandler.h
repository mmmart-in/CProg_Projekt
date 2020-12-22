#pragma once
#include <vector>
#include "Enemy.h"
#include "GameSystem.h"

#define ROW_HEIGHT 60
#define COL_WIDTH 80

	static Uint32 SDL_Ticks = 0;

class EnemyHandler : public Sprite
{
public:
	//konstruktor kanske ska ta rows+columns som argument istället för att göra det lättare senare
	//vill man här bestämma width och height för hela raden? det går ju att göra.
	static EnemyHandler* create_instance(int, int, int, int);
	std::vector<Enemy*> enemies_to_move();
	void tick();
	void draw();
	Collider* get_collider();
	void resolve_collision();
private:
	EnemyHandler(int startX, int startY, int rows, int cols);
	int speed = 20;
	bool moveLeft = false;
	int r = 0;
	int enemyCount = 0;
	int tickCount = 0;
	int count = 0; 
	Enemy* leftEnemy;
	Enemy* rightEnemy;
	void move(std::vector<Enemy*> enems);
	void outermost_enemies();
	void enemy_destroyed();
	void move_down();
	std::vector<Enemy*> enemies;

};

