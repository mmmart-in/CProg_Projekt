#include "Bullet.h"
#include "MainWIndow.h"
#include <iostream>


Bullet* Bullet::get_instance(int x, int y, int w, int h, std::string image) {
	return new Bullet(x, y, w, h, image);
}

Bullet::Bullet(int x, int y, int w, int h, std::string image) :
	MovableSprite(x, y, w, h, image) {
}

Bullet::~Bullet() {
	//Vi g�r new!!
	
}

void Bullet::tick() {
	rect.y -= 5;
}

void Bullet::draw() {
	SDL_RenderCopy(mainWindow.get_ren(), texture, NULL, &get_rect());
}