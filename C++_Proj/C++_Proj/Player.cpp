#include "Player.h"
#include "MainWindow.h"
#include <iostream>
#include "PlayerBullet.h"
#include <SDL_image.h>
#include "GameSystem.h"
#include "Input.h"


Player::Player(int x, int y, int w, int h): Sprite(x, y, w, h)
{
	//SKAPA ANIMATIONER H�R:::::
	forward = new Animation{"../../Resources/ship1.png"};
	turnRight = new Animation{"../../Resources/ship2.png"};
	turnLeft = new Animation{"../../Resources/ship3.png"};
	anim = new Animator{ forward, turnRight, turnLeft};
	hp = Health::get_instance(3);
	set_layer(1);
	set_tag("Player");
}

Player::~Player() {
	delete forward;
	delete turnLeft;
	delete turnRight;
	delete anim;
	delete hp;
}

void Player::tick() {
	
	hp->tick();

	get_collider()->getX() = get_rect().x;
	get_collider()->getY() = get_rect().y;

	handle_input();

	if (hitCooldown) {
		tickCount++;
		if (tickCount >= 60) {
			hitCooldown = false;
			tickCount = 0;
		}
	}	
}

Player* Player::create_instance(int x, int y, int w, int h) {
	return new Player(x, y, w, h);
}

void Player::handle_input() {
	if (input.get_key_down("Left") && get_rect().x > 0) {
		move_left();
		anim->next_image(turnLeftAnim);
	}
	else if (input.get_key_down("Right") && get_rect().x < 1200 - get_rect().w) {
		move_right();
		anim->next_image(turnRightAnim);
	}
	else
		anim->next_image(forwardAnim);

	if (input.get_key_down("Fire"))
		shoot();
}

void Player::move_left() {
	get_rect().x -= (gameSystem.get_deltatime() / 10) * moveSpeed;
}

void Player::move_right(){
	get_rect().x += (gameSystem.get_deltatime() / 10) * moveSpeed;

}

void Player::shoot() {
	if (fireCooldownCount <= SDL_GetTicks() - fireCooldown) {
		PlayerBullet* bptr = PlayerBullet::get_instance(get_rect().x + 10, get_rect().y - 25, 30, 30);
		gameSystem.get_current_scene().sprites->add(bptr);
		fireCooldownCount = SDL_GetTicks() + fireCooldown;
		gameSystem.get_audio_handler().player_shoot();
	}
}

void Player::draw() {
	anim->draw(this);
	hp->draw();
}


void Player::resolve_collision() {
	if(!hitCooldown)
		hp->get_hit();

	hitCooldown = true;
	
}

