#include "Enemy.h"
#include <SDL_image.h>
#include "Animator.h"

Enemy* Enemy::get_instance(int x, int y, int w, int h, int c, int r) 
{
	return new Enemy(x, y, w, h, c, r);
}

Enemy::Enemy(int x, int y, int w, int h, int c, int r) :
	MovableSprite(x, y, w, h, "nullvärde, parameter behövs ej"), col(c), row(r) {
	Animation idle{ "../../Resources/Fiende1_1.png",  "../../Resources/Fiende1_2.png" };
	anim = new Animator{idle};
}

Enemy::~Enemy() {

}

void Enemy::tick() {
	tickCount++;
	animate();
}

void Enemy::animate() {
	if(tickCount % 20 == 0)
	anim->next_image(0);
}

void Enemy::draw() {
	anim->draw(this);
}
void Enemy::move(bool moveLeft)
{
	if (moveLeft)
		rect.x -= 5;
	else
		rect.x += 5;
}
