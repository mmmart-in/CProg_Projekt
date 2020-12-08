#include <iostream>
#include <SDL.h>
#include "MainWindow.h"


void berättaOmGit() {
	std::cout << "Gitt är skoj, ojojoj!";
}

int main(int argc, char** argv) {
	SDL_Delay(2000);
	SDL_RenderPresent(mainWindow.get_ren());

	//Pushar igen då, RICKARD!!!

	std::cout<< "Hello world!";
	std::cout << "git e skitt";

	std::cout << "WOW, skoj med SDL" << std::endl;

	//I FIX
	//ÄR RICKARDS LINKER KVAR??? 
	// NUDÅ!?
	//FUNKAR FÖR MIG MEGALULZ

	berättaOmGit();

	return 0;
}