#include "Player.h"
#include "MainWIndow.h"

Player::Player(int x, int y, int w, int h, std::string image):
	MovableSprite(x, y, w, h, image)
{

}

void Player::tick() {
	//här händer saker hela tiden.. Beroende på vad som händer kalla på olika metoder

}

void Player::move() {
	
}

void Player::shoot() {

}

void Player::draw() {
	SDL_RenderCopy(mainWindow.get_ren(), texture, NULL, &get_rect());
}
