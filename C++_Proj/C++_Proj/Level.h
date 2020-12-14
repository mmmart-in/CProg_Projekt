#pragma once
#include "Player.h"
#include <vector>
#include "EnemyHandler.h"
#include <initializer_list>
class Level
{
public:
	Level(std::initializer_list<EnemyHandler>);
private:
	
	std::vector<EnemyHandler> allEnemies;
	
};

