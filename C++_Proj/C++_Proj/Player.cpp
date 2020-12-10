#include "Player.h"
#include "MainWIndow.h"
#include <iostream>
#include "Bullet.h"
#include <SDL_image.h>
#include "GameSystem.h"
#include "Input.h"

Player::Player(int x, int y, int w, int h, std::string image):
	MovableSprite(x, y, w, h, image)
{
	//SKAPA ANIMATIONER HÄR:::::
	
}

void Player::tick() {
	if (input.get_key_down("Left"))
		move_left();
	if (input.get_key_down("Right"))
		move_right();
	if (input.get_key_down("Fire"))
		shoot();
}

void Player::move_left() {
	rect.x -= movementSpeed;
	std::cout << "Move left" << std::endl;
}

void Player::move_right() {
	rect.x += movementSpeed;
	std::cout << "Move right" << std::endl;
}

void Player::shoot() {
	Bullet* bptr = Bullet::get_instance(rect.x, rect.y - firePoint, 30, 50, "../../Resources/bullet.png");
	gameSystem.add_sprites(bptr);
}

void Player::draw() {
	SDL_RenderCopy(mainWindow.get_ren(), texture, NULL, &get_rect());
}
