#include <iostream>
#include <SDL.h>


void berättaOmGit() {
	std::cout << "Gitt är skoj, ojojoj!";
}

int main(int argc, char** argv) {
	
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* win = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, NULL);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
	SDL_RenderPresent(ren);

	SDL_Delay(2000);

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