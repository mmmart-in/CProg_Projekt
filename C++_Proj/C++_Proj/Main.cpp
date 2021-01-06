#include "GameSystem.h"
#include "Input.h"

int main(int argc, char** argv) {
	

	input.add_keybind("Fire", SDL_SCANCODE_SPACE);
	input.add_keybind("Left", SDL_SCANCODE_LEFT);
	input.add_keybind("Right", SDL_SCANCODE_RIGHT);
	
	gameSystem.run();

	return 0;
}