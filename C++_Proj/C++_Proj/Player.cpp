#include "Player.h"
#include "MainWIndow.h"
#include <iostream>
Player::Player(int x, int y, int w, int h, std::string image):
	MovableSprite(x, y, w, h, image)
{
	//SKAPA ANIMATIONER H�R:::::
}

void Player::tick() {
	//h�r h�nder saker hela tiden.. Beroende p� vad som h�nder kalla p� olika metoder
	move();

}

void Player::move() {
	const Uint8* currentKeys = SDL_GetKeyboardState(NULL);

	if (currentKeys[SDL_SCANCODE_LEFT] && rect.x > 0)
		rect.x -= movementSpeed;
	if (currentKeys[SDL_SCANCODE_RIGHT] && rect.x < 1200 - rect.w)
		rect.x += movementSpeed;
}

void Player::shoot() {

}

void Player::draw() {
	SDL_RenderCopy(mainWindow.get_ren(), texture, NULL, &get_rect());
}
