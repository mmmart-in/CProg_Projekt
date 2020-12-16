#include <iostream>
#include <SDL.h>
#include "MainWindow.h"
#include <SDL_image.h>
#include "GameSystem.h"
#include "Player.h"
#include "Label.h"
#include "Input.h"
#include "Enemy.h"
#include "EnemyHandler.h"
#include <vector>
#include "Level.h"


int main(int argc, char** argv) {
	




	


	

	input.add_keybind("Fire", SDL_SCANCODE_SPACE);
	input.add_keybind("Left", SDL_SCANCODE_LEFT);
	input.add_keybind("Right", SDL_SCANCODE_RIGHT);
	

	//gameSystem.add_level(level1); och sen måste man ju kunna byta mellan levels i gamesystem också

	
	gameSystem.run();

	return 0;
}