#include <iostream>
#include <SDL.h>


void berättaOmGit() {
	std::cout << "Gitt är skoj, ojojoj!";
}

int main(int argc, char** argv) {
	
	SDL_Init(SDL_INIT_EVERYTHING);

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