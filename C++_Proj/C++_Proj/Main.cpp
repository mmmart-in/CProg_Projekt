#include <iostream>
#include <SDL.h>
#include "GameEngine.h"
#include "Component.h"

void berättaOmGit() {
	std::cout << "Gitt är skoj, ojojoj!";
}

int main(int argc, char** argv) {
	
	//SDL_Init(SDL_INIT_EVERYTHING);

	GameEngine engine;

	
	Component* c = new Component(1, 1, 1, 1);

	engine.add_component(c);
	engine.remove_component(c);


	//SDL_Quit();

	return 0;
		
}