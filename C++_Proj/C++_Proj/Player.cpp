#include "Player.h"
#include "MainWIndow.h"
#include <iostream>
#include "Bullet.h"
#include <SDL_image.h>
#include "GameSystem.h"

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
	move();
	shoot();

}

void Player::move() {
	const Uint8* currentKeys = SDL_GetKeyboardState(NULL);

	if (currentKeys[SDL_SCANCODE_LEFT] && rect.x > 0) {
		rect.x -= movementSpeed;
		anim->next_image(turnLeftAnim);
	}
		
	else if (currentKeys[SDL_SCANCODE_RIGHT] && rect.x < 1200 - rect.w) {
		rect.x += movementSpeed;
		anim->next_image(turnRightAnim);
	}

	else
		anim->next_image(forwardAnim);

	

	
		
}

void Player::shoot() {
	const Uint8* currentKeys = SDL_GetKeyboardState(NULL);

	if (currentKeys[SDL_SCANCODE_SPACE]) {
		if (fireCooldownCount <= SDL_GetTicks() - fireCooldown) {
			Bullet* bptr = Bullet::get_instance(rect.x, rect.y - firePoint, 30, 30, "../../Resources/bullet.png");
			gameSystem.add_sprites(bptr);
			fireCooldownCount = SDL_GetTicks() + fireCooldown;
		}
	}
		
}

void Player::draw() {
	anim->draw(this);
}
