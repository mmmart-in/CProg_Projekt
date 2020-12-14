#pragma once
#include "Player.h"
#include <vector>
#include "EnemyHandler.h"
#include <initializer_list>
class Level
{
public:
	Level(Player, std::initializer_list<EnemyHandler>);
private:
	Player player;
	std::vector<EnemyHandler> allEnemies;
	
};

