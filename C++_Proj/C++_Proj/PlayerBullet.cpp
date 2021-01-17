#include "PlayerBullet.h"
#include <iostream>


PlayerBullet* PlayerBullet::get_instance(int x, int y, int w, int h) {
	return new PlayerBullet(x, y, w, h);
}

PlayerBullet::PlayerBullet(int x, int y, int w, int h) :
	Bullet(x, y, w, h) {
	animation = new Animation{ "../../Resources/bullet1.png",
	"../../Resources/bullet2.png",
	"../../Resources/bullet3.png",
	"../../Resources/bullet4.png" };

	anim = new Animator{ animation };
	tickCount = 0;
	set_layer(2);
	set_tag("playerbullet");
}

void PlayerBullet::tick() {
	Bullet::tick();
	if (get_rect().y <= 0)
		gameSystem.get_current_scene().sprites->remove(this);
}

void PlayerBullet::move() {
	get_rect().y -= (gameSystem.get_deltatime() / 10) * movementSpeed;
	get_collider()->getX() = get_rect().x;
	get_collider()->getY() = get_rect().y;

}
