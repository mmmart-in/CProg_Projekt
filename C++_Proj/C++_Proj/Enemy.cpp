#include "Enemy.h"
#include <SDL_image.h>
#include "Animator.h"

Enemy* Enemy::get_instance(int x, int y, int w, int h) 
{
	return new Enemy(x, y, w, h);
}

Enemy::Enemy(int x, int y, int w, int h) :
	MovableSprite(x, y, w, h, "nullvärde, parameter behövs ej") {
	enemyCount++;
	Animation idle{ "../../Resources/Fiende1_1.png",  "../../Resources/Fiende1_2.png" };
	anim = new Animator{idle};
}

Enemy::~Enemy() {
	enemyCount--;
}

void Enemy::tick() {
	tickCount++;
	animate();
}

void Enemy::animate() {
	if(tickCount % 50 == 0)
	anim->next_image(0);
}

void Enemy::draw() {
	anim->draw(this);
}