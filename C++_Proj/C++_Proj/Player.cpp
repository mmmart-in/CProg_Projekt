#include "Player.h"
#include "MainWIndow.h"
#include <iostream>
#include "Bullet.h"
#include <SDL_image.h>
#include "GameSystem.h"

Player::Player(int x, int y, int w, int h, std::string image):
	MovableSprite(x, y, w, h, image)
{
	//SKAPA ANIMATIONER HÄR:::::
	Animation forward{"../../Resources/ship1.png"};
	Animation turnRight{"../../Resources/ship2.png"};
	Animation turnLeft{"../../Resources/ship3.png"};
	anim = new Animator{ forward, turnRight, turnLeft};
	
}

void Player::tick() {
	//här händer saker hela tiden.. Beroende på vad som händer kalla på olika metoder
	move();
	shoot();

}

void Player::move() {
	const Uint8* currentKeys = SDL_GetKeyboardState(NULL);

	if (currentKeys[SDL_SCANCODE_LEFT] && rect.x > 0) {
		rect.x -= movementSpeed;
		anim->animate_loop(turnLeftAnim);
	}
		
	else if (currentKeys[SDL_SCANCODE_RIGHT] && rect.x < 1200 - rect.w) {
		rect.x += movementSpeed;
		anim->animate_loop(turnRightAnim);
	}

	else
		anim->animate_loop(forwardAnim);

	

	
		
}

void Player::shoot() {
	const Uint8* currentKeys = SDL_GetKeyboardState(NULL);

	if (currentKeys[SDL_SCANCODE_SPACE]) {
		Bullet* bptr = Bullet::get_instance(rect.x, rect.y - firePoint, 30, 50, "../../Resources/bullet.png");
		gameSystem.add_sprites(bptr);
	}
		
}

void Player::draw() {
	anim->draw(this);
}
