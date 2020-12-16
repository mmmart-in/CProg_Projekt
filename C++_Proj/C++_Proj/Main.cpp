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
	EnemyHandler* eh2 = EnemyHandler::create_instance(10, 20, 4,8);

	

	Player* player = Player::create_instance(600, 700, 50, 50);
	Player* player2 = Player::create_instance(600, 700, 50, 50);
	
	
		
	Label* lb = Label::getInstance(0, 0, 100, 50, "Score", { 255, 255, 255 });
	Label* lb2 = Label::getInstance(0, 0, 200, 100, "Second score", { 255, 255, 255 });

	Scene* main_menu = Scene::create_instance("Main Menu", 0);
	Scene* first_scene = Scene::create_instance("Level 1", 1);
	Scene* second_scene = Scene::create_instance("Level 2", 2);

	
	Label* header = Label::getInstance(350, 100, 500, 100, "SPACE INVADERS", { 100, 100, 255 });
	Label* play_instruction = Label::getInstance(450, 300, 300, 50, "Press F1 to play!", { 255, 255, 255 });

	main_menu->add_component(header);
	main_menu->add_component(play_instruction);

	first_scene->add_sprite(eh);
	first_scene->add_sprite(player);
	first_scene->add_component(lb);

	second_scene->add_sprite(eh2);
	second_scene->add_sprite(player2);
	second_scene->add_component(lb2);

	input.add_keybind("Fire", SDL_SCANCODE_SPACE);
	input.add_keybind("Left", SDL_SCANCODE_LEFT);
	input.add_keybind("Right", SDL_SCANCODE_RIGHT);
	

	//gameSystem.add_level(level1); och sen måste man ju kunna byta mellan levels i gamesystem också

	gameSystem.add_new_scenes({main_menu, second_scene, first_scene});
	gameSystem.run();

	return 0;
}