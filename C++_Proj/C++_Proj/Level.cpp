#include "Level.h"

Level::Level(Player p, std::initializer_list<EnemyHandler> e) {
	player = p;
	allEnemies = e;
}