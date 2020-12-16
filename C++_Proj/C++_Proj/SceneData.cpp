#include "SceneData.h"
#include "Label.h"
#include "EnemyHandler.h"
#include "Player.h"

Scene* SceneData::load_menu() {
	Scene* main_menu = Scene::create_instance();
	Label* header = Label::getInstance(300, 100, 600, 100, "SPACE INVADERS", { 100, 100, 255 });
	Label* play_instruction = Label::getInstance(450, 300, 300, 50, "Press F1 to play!", { 255, 255, 255 });

	main_menu->components->add(header);
	main_menu->components->add(play_instruction);
	return main_menu;
}

Scene* SceneData::load_gameplay(int r, int c) {
	Scene* scene = Scene::create_instance();
	EnemyHandler* eh = EnemyHandler::create_instance(10, 20, r, c);
	Player* p = Player::create_instance(600, 700, 50, 50);
	Label* lb = Label::getInstance(0, 0, 100, 100, "Score", { 255, 255, 255 });
	scene->components->add(lb);
	scene->sprites->add(p);
	scene->sprites->add(eh);

	return scene;
}

SceneData sceneData;