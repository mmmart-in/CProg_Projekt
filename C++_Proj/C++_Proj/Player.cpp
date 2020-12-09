#include "Player.h"
#include "MainWIndow.h"
#include <iostream>
Player::Player(int x, int y, int w, int h, std::string image):
	MovableSprite(x, y, w, h, image)
{

}

void Player::tick() {
	//här händer saker hela tiden.. Beroende på vad som händer kalla på olika metoder
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
<<<<<<< Updated upstream

=======
	const Uint8* currentKeys = SDL_GetKeyboardState(NULL);
	if (currentKeys[SDL_SCANCODE_SPACE]) {
		Bullet* bptr = Bullet::get_instance(rect.x, rect.y - firePoint, 30, 50, "../../Resources/bullet.png");
		gameSystem.add_sprites(bptr);
	}
>>>>>>> Stashed changes
}

void Player::draw() {
	SDL_RenderCopy(mainWindow.get_ren(), texture, NULL, &get_rect());
}
