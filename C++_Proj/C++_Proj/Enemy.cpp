#include "Enemy.h"


Enemy::Enemy(int x, int y, int w, int h) :
	MovableSprite(x, y, w, h) {
	enemyCount++;
}

Enemy::~Enemy() {
	enemyCount--;
}

void Enemy::tick() {

}