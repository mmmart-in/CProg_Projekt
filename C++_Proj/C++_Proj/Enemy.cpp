#include "Enemy.h"


Enemy::Enemy(int x, int y, int w, int h, std::string image) :
	MovableSprite(x, y, w, h, image) {
	enemyCount++;
}

Enemy::~Enemy() {
	enemyCount--;
}

void Enemy::tick() {
	
}