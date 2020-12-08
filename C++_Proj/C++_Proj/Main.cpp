#include <iostream>
#include <SDL.h>
#include "MainWindow.h"
#include <SDL_image.h>
#include "GameSystem.h"
#include "Player.h"
#include "Label.h"

int main(int argc, char** argv) {

	Player p(600, 700, 50, 50, "../../Resources/Player.png");

	Label* lb = Label::getInstance(0, 0, 100, 100, "Score", { 255, 255, 255 });

	GameSystem gameSystem;

	gameSystem.add_sprites(&p);
	gameSystem.add_component(lb);
	
	gameSystem.run();

	return 0;
}