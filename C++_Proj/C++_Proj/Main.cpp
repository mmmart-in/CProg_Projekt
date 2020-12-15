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
	EnemyHandler* eh = EnemyHandler::create_instance(10, 20, 3,5);
	EnemyHandler* eh2 = EnemyHandler::create_instance(10, 20, 3,5);


	Player* player = Player::create_instance(600, 700, 50, 50, "../../Resources/Player.png");
	Player* player2 = Player::create_instance(600, 700, 50, 50, "../../Resources/Player.png");
	
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
	Label* lb2 = Label::getInstance(0, 0, 200, 100, "Second score", { 255, 255, 255 });

	Scene* main_menu = Scene::create_instance("Main Menu", 0);
	Scene* first_scene = Scene::create_instance("Level 1", 1);
	Scene* second_scene = Scene::create_instance("Level 2", 2);

	
	Label* header = Label::getInstance(450, 100, 300, 100, "SPACE INVADERS", { 255, 255, 255 });
	Label* play_instruction = Label::getInstance(450, 300, 300, 50, "Press F1 to play!", { 255, 255, 255 });

	main_menu->components->add(header);
	main_menu->components->add(play_instruction);

	first_scene->sprites->add(eh);
	first_scene->sprites->add(player);
	first_scene->components->add(lb);

	second_scene->sprites->add(eh2);
	second_scene->sprites->add(player2);
	second_scene->components->add(lb2);

	input.add_keybind("Fire", SDL_SCANCODE_SPACE);
	input.add_keybind("Left", SDL_SCANCODE_LEFT);
	input.add_keybind("Right", SDL_SCANCODE_RIGHT);
	

	//gameSystem.add_level(level1); och sen måste man ju kunna byta mellan levels i gamesystem också

	gameSystem.add_new_scenes({main_menu, second_scene, first_scene});
	gameSystem.run();

	return 0;
}