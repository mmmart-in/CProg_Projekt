#include <iostream>
#include <SDL.h>
#include "MainWindow.h"
#include <SDL_image.h>
#include "GameSystem.h"
#include "Player.h"
#include "Label.h"
#include "Input.h"
#include "Enemy.h"
#include "EnemyHandler.h"


int main(int argc, char** argv) {
	EnemyHandler eh(100, 100, 7);
	EnemyHandler eh2(100, 200, 7);
	EnemyHandler eh3(100, 300, 7);

	Player p(600, 700, 50, 50, "../../Resources/Player.png");

	Label* lb = Label::getInstance(0, 0, 100, 100, "Score", { 255, 255, 255 });

	input.add_keybind("Fire", SDL_SCANCODE_SPACE);
	input.add_keybind("Left", SDL_SCANCODE_LEFT);
	input.add_keybind("Right", SDL_SCANCODE_RIGHT);
	


	

	gameSystem.add_sprites(&p);
	gameSystem.add_component(lb);
	
	gameSystem.run();

	return 0;
}