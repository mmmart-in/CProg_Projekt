#include "Enemy.h"
#include <SDL_image.h>
#include "Animator.h"
#include "GameSystem.h"
#include "EnemyBullet.h"
#include <iostream>
#include "AudioHandler.h"


Enemy* Enemy::get_instance(int x, int y, int w, int h, int c, int r)
{
	return new Enemy(x, y, w, h, c, r);
}

Enemy::Enemy(int x, int y, int w, int h, int c, int r) : Sprite(x, y, w, h), col(c), row(r) {
	idle = new Animation{ "../../Resources/enemy1.png",
		"../../Resources/enemy2.png",
		"../../Resources/enemy3.png",
		"../../Resources/enemy4.png" ,
		"../../Resources/enemy5.png" ,
		"../../Resources/enemy6.png" };
	anim = new Animator{idle};
	set_layer(2);
	set_tag("Enemy");
}

Enemy::~Enemy() {
	delete idle;
	delete anim;
}

void Enemy::tick() {

	tickCount++;
	animate();
}

void Enemy::animate() {
	if(tickCount % 5 == 0)
	anim->next_image(0);
}

void Enemy::draw() {
	anim->draw(this);
}


void Enemy::move(bool moveLeft)
{
	if (moveLeft)
		get_rect().x -= (gameSystem.get_deltatime() / 10) * moveSpeed;
	else
		get_rect().x += (gameSystem.get_deltatime() / 10) * moveSpeed;

	get_collider()->getX() = get_rect().x;
	get_collider()->getY() = get_rect().y;
	
	
}

void Enemy::Shoot() {
	EnemyBullet* bptr = EnemyBullet::get_instance(get_rect().x + 20, get_rect().y + 40, 20, 20);
	gameSystem.get_current_scene().sprites->add(bptr);
	audioHandler.enemy_shoot();
}

void Enemy::resolve_collision() {
	std::cout << "Fiende träffad" << std::endl;
	notify();
}

