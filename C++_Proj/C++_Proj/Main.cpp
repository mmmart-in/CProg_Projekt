#include <iostream>
#include <SDL.h>
#include "MainWindow.h"
#include <SDL_image.h>
#include "GameSystem.h"
#include "Player.h"


void berättaOmGit() {
	std::cout << "Gitt är skoj, ojojoj!";
}



int main(int argc, char** argv) {

	std::string alienPNG = "C:/resources/alien.png";

	Player p(100, 100, 100, 100, alienPNG);

	SDL_RenderPresent(mainWindow.get_ren());
	SDL_Delay(5000);

	

	return 0;
}