#include "SceneData.h"
#include "Label.h"
#include "Score.h"
#include "EnemyHandler.h"
#include "Player.h"
#include "Castle.h"
#include "Background.h"

Scene* SceneData::load_menu() {
	Scene* main_menu = Scene::create_instance();

	return main_menu;
}

Scene* SceneData::load_gameplay(int r, int c) {

	Scene* scene = Scene::create_instance();
	Background* b = Background::get_instance(0, 0, 1200, 800);
	EnemyHandler* eh = EnemyHandler::create_instance(10, 20, r, c);
	Player* p = Player::create_instance(600, 700, 50, 50);
	Castle* c1 = Castle::get_instance(200, 500, 60, 60);
	Castle* c2 = Castle::get_instance(550, 500, 60, 60);
	Castle* c3 = Castle::get_instance(900, 500, 60, 60);
	scene->sprites->add(b);
	scene->sprites->add(p);
	scene->sprites->add(c1);
	scene->sprites->add(c2);
	scene->sprites->add(c3);
	scene->sprites->add(eh);

	return scene;
}
