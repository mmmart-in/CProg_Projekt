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
	//SKAPA ANIMATIONER H�R:::::
	Animation forward{"../../Resources/ship1.png"};
	Animation turnRight{"../../Resources/ship2.png"};
	Animation turnLeft{"../../Resources/ship3.png"};
	anim = new Animator{ forward, turnRight, turnLeft};
	
}

void Player::tick() {
	//h�r h�nder saker hela tiden.. Beroende p� vad som h�nder kalla p� olika metoder
	
	if (input.get_key_down("Left") && rect.x > 0) {
		move_left();
		anim->animate_loop(turnLeftAnim);
	} else if (input.get_key_down("Right") && rect.x < 1200 - rect.w) {
		move_right();
		anim->animate_loop(turnRightAnim);
	} else
		anim->animate_loop(forwardAnim);
	
	if (input.get_key_down("Fire"))
		shoot();
	
}

void Player::move_left() {
	rect.x -= movementSpeed;
}

void Player::move_right(){
	rect.x += movementSpeed;

}

void Player::shoot() {
	if (fireCooldownCount <= SDL_GetTicks() - fireCooldown) {
		Bullet* bptr = Bullet::get_instance(rect.x, rect.y - firePoint, 30, 50, "../../Resources/bullet.png");
		gameSystem.add_sprites(bptr);
		fireCooldownCount = SDL_GetTicks() + fireCooldown;
	}
		
}

void Player::draw() {
	anim->draw(this);
}
