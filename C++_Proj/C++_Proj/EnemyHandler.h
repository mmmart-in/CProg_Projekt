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
	std::vector<Enemy*> enemies_to_move();

	//konstruktor kanske ska ta rows+columns som argument istället för att göra det lättare senare
	//vill man här bestämma width och height för hela raden? det går ju att göra.
	static EnemyHandler* create_instance(int, int, int, int);
	void tick();
	void draw();
	void remove_enemy(Enemy*);
	void resolve_collision();
	Collider* get_collider();
	std::vector<Enemy*> get_enemies();
	
private:
	int enemyCount = 0;
	int tickCount = 0;
	int count = 0;
	int r = 0;
	int speed = 20;
	bool moveLeft = false;
	Enemy* leftEnemy;
	Enemy* rightEnemy;
	std::vector<Enemy*> enemies;

private:
	EnemyHandler(int startX, int startY, int rows, int cols);
	void move(std::vector<Enemy*> enems);
	void outermost_enemies();
	void enemy_destroyed();
	void move_down();

};

