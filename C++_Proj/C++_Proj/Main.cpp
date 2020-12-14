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
	EnemyHandler eh(100, 100, 3,5);


	Player p(600, 700, 50, 50, "../../Resources/Player.png");
	
	/*
	Så här vil jag typ göra istället för som ovan.
	Och sen ladda in en level till gameSystem istället. 
	och i gameSYstem måste man kunna lägga till en level som delar ut sina objekt till comps och sprites osv.
	
	Level level1(Player (600, 700, 50, 50, "../../Resources/Player.png"),
		{EnemyHandler(100, 100, 7),
		EnemyHandler (100, 200, 7),
		EnemyHandler (100, 300, 7) });
	*/
		
	Label* lb = Label::getInstance(0, 0, 100, 100, "Score", { 255, 255, 255 });




	input.add_keybind("Fire", SDL_SCANCODE_SPACE);
	input.add_keybind("Left", SDL_SCANCODE_LEFT);
	input.add_keybind("Right", SDL_SCANCODE_RIGHT);
	

	//gameSystem.add_level(level1); och sen måste man ju kunna byta mellan levels i gamesystem också
	gameSystem.add_sprites(&eh);

	gameSystem.add_sprites(&p);
	gameSystem.add_component(lb);
	
	gameSystem.run();

	return 0;
}