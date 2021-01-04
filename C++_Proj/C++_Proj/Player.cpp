#include "Player.h"
#include "MainWindow.h"
#include <iostream>
#include "PlayerBullet.h"
#include <SDL_image.h>
#include "GameSystem.h"
#include "Input.h"
#include "Log.h"

#include "AudioHandler.h"

Player::Player(int x, int y, int w, int h):
	MovableSprite(x, y, w, h)
{
	//SKAPA ANIMATIONER HÄR:::::
	Animation forward{"../../Resources/ship1.png"};
	Animation turnRight{"../../Resources/ship2.png"};
	Animation turnLeft{"../../Resources/ship3.png"};
	anim = new Animator{ forward, turnRight, turnLeft};
	layer = 1;
	tag = "player";
}

void Player::tick() {
	//här händer saker hela tiden.. Beroende på vad som händer kalla på olika metoder
	
	collider->x = rect.x;
	collider->y = rect.y;

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
	rect.x -= (gameSystem.deltaTime / 10) * moveSpeed;
}

void Player::move_right(){
	rect.x += (gameSystem.deltaTime / 10) * moveSpeed;

}

void Player::shoot() {
	if (fireCooldownCount <= SDL_GetTicks() - fireCooldown) {
		PlayerBullet* bptr = PlayerBullet::get_instance(rect.x + 20, rect.y - 40, 30, 30);
		gameSystem.get_current_scene()->sprites->add(bptr);
		fireCooldownCount = SDL_GetTicks() + fireCooldown;
		
		audioHandler.player_shoot();
	}

}

void Player::draw() {
	anim->draw(this);
}



void Player::resolve_collision() {
	
}
