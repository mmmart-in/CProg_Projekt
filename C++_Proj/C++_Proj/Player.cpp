#include "Player.h"
#include "MainWindow.h"
#include <iostream>
#include "Bullet.h"
#include <SDL_image.h>
#include "GameSystem.h"
#include "Input.h"
#include "Log.h"
Player::Player(int x, int y, int w, int h):
	MovableSprite(x, y, w, h)
{
	//SKAPA ANIMATIONER HÄR:::::
	Animation forward{"../../Resources/ship1.png"};
	Animation turnRight{"../../Resources/ship2.png"};
	Animation turnLeft{"../../Resources/ship3.png"};
	anim = new Animator{ forward, turnRight, turnLeft};
	
}

void Player::tick() {
	//här händer saker hela tiden.. Beroende på vad som händer kalla på olika metoder
	
	if (input.get_key_down("Left") && rect.x > 0) {
		move_left();
		anim->next_image(turnLeftAnim);
	} else if (input.get_key_down("Right") && rect.x < 1200 - rect.w) {
		move_right();
		anim->next_image(turnRightAnim);
	} else
		anim->next_image(forwardAnim);
	
	if (input.get_key_down("Fire"))
		shoot();
	
}

Player* Player::create_instance(int x, int y, int w, int h) {
	return new Player(x, y, w, h);
}

void Player::move_left() {
	rect.x -= movementSpeed;
}

void Player::move_right(){
	rect.x += movementSpeed;

}

void Player::shoot() {
	if (fireCooldownCount <= SDL_GetTicks() - fireCooldown) {
		Bullet* bptr = Bullet::get_instance(rect.x, rect.y - firePoint, 30, 30);
		gameSystem.get_current_scene()->add_sprite(bptr);
		fireCooldownCount = SDL_GetTicks() + fireCooldown;
	}
}

void Player::draw() {
	anim->draw(this);
}
