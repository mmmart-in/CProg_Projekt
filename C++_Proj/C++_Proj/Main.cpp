#include <iostream>
#include <SDL.h>
#include "MainWindow.h"
#include <SDL_image.h>
#include "GameSystem.h"
#include "Player.h"
#include "Label.h"

void berättaOmGit() {
	std::cout << "Gitt är skoj, ojojoj!";
}



int main(int argc, char** argv) {

	std::string alienPNG = "C:/resources/alien.png";

	Player p(100, 100, 100, 100, alienPNG);
	Label* lb = Label::getInstance(100, 200, 100, 100, "hejehj", { 255, 255, 255 });
	GameSystem gameSystem;
	gameSystem.add_sprites(&p);
	gameSystem.add_component(lb);
	gameSystem.run();
	return 0;
}