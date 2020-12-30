#include "Bullet.h"
#include "MainWIndow.h"
#include <iostream>
#include "Animation.h"
#include "Log.h"
#include "GameSystem.h"

Bullet* Bullet::get_instance(int x, int y, int w, int h) {
	return new Bullet(x, y, w, h);
}

Bullet::Bullet(int x, int y, int w, int h) :
	MovableSprite(x, y, w, h) {
	Animation idle{ "../../Resources/bullet1.png",
	"../../Resources/bullet2.png",
	"../../Resources/bullet3.png", 
	"../../Resources/bullet4.png"};
	
	anim = new Animator{idle};
	tickCount = 0;
	layer = 2;
	tag = "bullet";
}

Bullet::~Bullet() {
	std::cout << "bullet destructor" << std::endl;
	delete anim;
}

void Bullet::tick() {
	tickCount++;
	move();
	animate();
	if (rect.y <= 0)
		gameSystem.get_current_scene()->sprites->remove(this);
}

void Bullet::move() {
	rect.y -= (gameSystem.deltaTime / 10) * movementSpeed;
	collider->x = rect.x;
	collider->y = rect.y;
	
}

void Bullet::animate() {
	if (tickCount % 5 == 0) {
		anim->next_image(0);
	}
}

void Bullet::draw() {
	anim->draw(this);
}

Collider* Bullet::get_collider() {
	return collider;
}

void Bullet::resolve_collision() {
	
	gameSystem.get_current_scene()->sprites->remove(this);
}

