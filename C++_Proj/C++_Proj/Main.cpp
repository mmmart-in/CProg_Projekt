#include <iostream>
#include <SDL.h>
#include "MainWindow.h"
#include <SDL_image.h>
#include "GameSystem.h"
#include "Player.h"


void berättaOmGit() {
	std::cout << "Gitt är skoj, ojojoj!";
}

std::string alienPNG = "C:/resources/alien.png"

int main(int argc, char** argv) {


	Player p(100, 100, 100, 100);

	SDL_RenderPresent(mainWindow.get_ren());
	SDL_Delay(5000);

	

	return 0;
}