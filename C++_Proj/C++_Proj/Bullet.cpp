#include "Bullet.h"
#include "MainWIndow.h"
#include <iostream>
#include "Animation.h"


Bullet* Bullet::get_instance(int x, int y, int w, int h, std::string image) {
	return new Bullet(x, y, w, h, image);
}

Bullet::Bullet(int x, int y, int w, int h, std::string image) :
	MovableSprite(x, y, w, h, image) {
	Animation idle{ "../../Resources/bullet1.png",
	"../../Resources/bullet2.png",
	"../../Resources/bullet3.png", 
	"../../Resources/bullet4.png"};

	anim = new Animator{idle};
	tickCount = 0;
	
}

Bullet::~Bullet() {
	//Vi gör new!!
	
}

void Bullet::tick() {
	tickCount++;
	rect.y -= 5;
	fly();
}

void Bullet::fly() {
	if (tickCount % 10 == 0) {
		anim->next_image(0);
	}
}

void Bullet::draw() {
	anim->draw(this);
}