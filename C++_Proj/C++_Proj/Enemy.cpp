#include "Enemy.h"
#include <SDL_image.h>
#include "Animator.h"


Enemy::Enemy(int x, int y, int w, int h, std::string enemyType) :
	MovableSprite(x, y, w, h, enemyType) {
	enemyCount++;
	Animation idle{ "../../Resources/Fiende1_1.png",  "../../Resources/Fiende1_2.png" };
	anim = new Animator{idle};
}

Enemy::~Enemy() {
	enemyCount--;
}

void Enemy::tick() {
	
}

void Enemy::draw() {
	anim->draw(this);
}