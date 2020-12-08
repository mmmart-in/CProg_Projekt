#include <iostream>
#include <SDL.h>
#include "MainWindow.h"
#include <SDL_image.h>
#include "GameSystem.h"


void berättaOmGit() {
	std::cout << "Gitt är skoj, ojojoj!";
}

int main(int argc, char** argv) {

	SDL_Surface* alien = IMG_Load("C:/resources/alien.png");
	SDL_Texture* alienText = SDL_CreateTextureFromSurface(mainWindow.get_ren(), alien);
	SDL_FreeSurface(alien);
	SDL_RenderCopy(mainWindow.get_ren(), alienText, NULL, NULL);

	SDL_RenderPresent(mainWindow.get_ren());
	SDL_Delay(5000);

	

	return 0;
}