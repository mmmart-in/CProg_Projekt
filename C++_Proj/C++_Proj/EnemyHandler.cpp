#include "EnemyHandler.h"
#include <iostream>


EnemyHandler::EnemyHandler(int startX, int startY, int rows, int cols) : Sprite(1, 1, 1, 1), r(rows - 1)
{	
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
		Enemy* e = Enemy::get_instance(startX + i * COL_WIDTH, startY + j * ROW_HEIGHT, 55, 55, i, j);
		e->attach(*this);
		enemies.push_back(e);
		enemyCount++;
		}
	}
	enemiesAlive = enemies.size();
	count = r;
	outermost_enemies();
	set_layer(10);
	set_tag("enemyhandler");
	
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
	Shoot();
	if (tickCount % (enemiesAlive /2) == 0) 
	{
		move(enemies_to_move());
		tickCount = 0;
	}
	
	
}

EnemyHandler::~EnemyHandler() {
	delete leftEnemy;
	delete rightEnemy;

	for (Enemy* e : enemies) {
		delete e;
	}

	enemies.clear();
}

void EnemyHandler::move_down() 
{
	for (Enemy* e : enemies)
		e->get_rect().y += ROW_HEIGHT;
}
void EnemyHandler::draw() 
{
	for (Enemy* e : enemies) {
		e->draw();
	}
}

std::vector<Enemy*> EnemyHandler::enemies_to_move() {
	std::vector<Enemy*> enemiesToMove;

	for (Enemy* e : enemies) {
		if (e->row == count)
			enemiesToMove.push_back(e);
	}
	count == 0 ? count = r : count--;
	return enemiesToMove;
}
void EnemyHandler::move(std::vector<Enemy*> enems)
{
	//nåt skumt här???
	if (moveLeft && leftEnemy->get_rect().x <= 5) {
		moveLeft = false;
		move_down();
		
	}
	else if (!moveLeft && rightEnemy->get_rect().x > 1200 - rightEnemy->get_rect().w) {
		moveLeft = true;
		move_down();
	}

	
	for (Enemy* e : enems) 
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

Collider* EnemyHandler::get_collider() {
	return get_collider();
}

void EnemyHandler::resolve_collision() {
	
}

std::vector<Enemy*> EnemyHandler::get_enemies() {
	return enemies;
}

void EnemyHandler::callback(EventSubject& object) {
	remove_enemy(dynamic_cast<Enemy*>(&object));
	gameSystem.get_current_scene().sprites->remove(dynamic_cast<Enemy*>(&object));
}

void EnemyHandler::remove_enemy(Enemy* e) {
	
	std::cout << enemiesAlive<<std::endl;
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i] == e) {
			if(enemiesAlive > 3)
				enemiesAlive--;
			enemies.erase(enemies.begin() + i);
		}
			
	}

	if (enemies.empty()) {
		gameSystem.game_over(true);
		return;
	}
		

	leftEnemy = *(enemies.begin());
	rightEnemy = *(enemies.end() - 1);
}

void EnemyHandler::Shoot() {
	if ((rand() % 100) + 1 < 3) {
		if (enemies.size() == 1) {
			enemies[0]->Shoot();
		}
		else {
			int randomNumber = (rand() % (enemies.size() - 1)) + 1;
			enemies[randomNumber]->Shoot();
		}
	}
	
}

void EnemyHandler::add_enemies_to_scene(Scene* scene) {
	for (Enemy* e : enemies) {
		scene->sprites->add(e);
	}
}