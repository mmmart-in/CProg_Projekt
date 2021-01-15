#include "EnemyBullet.h"
#include <iostream>

EnemyBullet* EnemyBullet::get_instance(int x, int y, int w, int h) {
	return new EnemyBullet(x, y, w, h);
}

EnemyBullet::EnemyBullet(int x, int y, int w, int h) :
	Bullet(x, y, w, h) {
	animation = new Animation{ "../../Resources/eBullet1.png",
	"../../Resources/eBullet2.png",
	"../../Resources/eBullet3.png",
	"../../Resources/eBullet4.png" };

	anim = new Animator{ animation };
	tickCount = 0;
	layer = 1;
	tag = "enemybullet";
}


void EnemyBullet::tick() {
	Bullet::tick();
	if (rect.y >= 800)
		gameSystem.get_current_scene().sprites->remove(this);
}

void EnemyBullet::move() {
	rect.y += (gameSystem.get_deltatime() / 10) * movementSpeed;
	collider->x = rect.x;
	collider->y = rect.y;

}