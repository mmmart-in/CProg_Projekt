#include "PlayerBullet.h"
#include <iostream>


PlayerBullet* PlayerBullet::get_instance(int x, int y, int w, int h) {
	return new PlayerBullet(x, y, w, h);
}

PlayerBullet::PlayerBullet(int x, int y, int w, int h) :
	Bullet(x, y, w, h) {
	Animation idle{ "../../Resources/bullet1.png",
	"../../Resources/bullet2.png",
	"../../Resources/bullet3.png",
	"../../Resources/bullet4.png" };

	anim = new Animator{ idle };
	tickCount = 0;
	layer = 2;
	tag = "bullet";
}

PlayerBullet::~PlayerBullet() {
	
	delete anim;
}
void PlayerBullet::tick() {
	Bullet::tick();
	if (rect.y <= 0)
		gameSystem.get_current_scene()->sprites->remove(this);
}


void PlayerBullet::move() {
	rect.y -= (gameSystem.deltaTime / 10) * movementSpeed;
	collider->x = rect.x;
	collider->y = rect.y;

}
