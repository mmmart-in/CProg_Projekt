#include "Bullet.h"
#include "MainWIndow.h"
#include <iostream>
#include "Animation.h"
#include "Log.h"
#include "GameSystem.h"



Bullet::Bullet(int x, int y, int w, int h) : Sprite(x, y, w, h) {
	
}

Bullet::~Bullet() {
	delete animation;
	delete anim;
}

void Bullet::tick() {
	tickCount++;
	move();
	animate();
	
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



void Bullet::resolve_collision() {
	
	gameSystem.get_current_scene()->sprites->remove(this);
}

