#include "GameSystem.h"
#include <SDL.h>
#include <iostream>
#include "Input.h"
#include <chrono>
#include "SceneData.h"
#include "EnemyHandler.h"
#include <typeinfo>
#include "Options.h"

GameSystem::GameSystem() {
	mainWindow = new MainWindow();
	UI_manager = UIManager::create_instance(&get_renderer());
}

void GameSystem::run() {
	deltaTime = 0;

	load_new_scene(Scene::create_instance(), "Menu");
	
	Uint32 tickInterval = 1000 / FPS;

	while (running) {

		if (gameover)
			load_new_scene(sceneData->load_menu(), "Menu");

		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		

		SDL_RenderClear(&get_renderer());

		
		update_sprites();
		update_components();
		UI_manager->update_UI();
		SDL_RenderPresent(&get_renderer());
		
		deltaTime = nextTick - SDL_GetTicks();


		if (deltaTime > 0)
			SDL_Delay(deltaTime);
			
		
		update_scene_objects();
		check_collision();
		handle_input();
	
	}
}

void GameSystem::check_collision() {

	for (int i = 0; i < collision_layers.size(); i++) {
		for (int j = 0; j < collision_layers.size(); j++) {
			if (collision_layers[i]->get_collider()->check_collision(*collision_layers[j]->get_collider()))
				if (collision_layers[i]->get_tag() != collision_layers[j]->get_tag() &&
					collision_layers[i]->get_layer() == collision_layers[j]->get_layer()) 
				{
					collision_layers[i]->resolve_collision();
					collision_layers[j]->resolve_collision();
				}
		}
	}
}




void GameSystem::update_sprites() {
	for (Sprite* sprite : active_sprites) {
		sprite->tick();
		sprite->draw();
	}
}

void GameSystem::update_components() {
	for (Component* component : active_components) {
		component->tick();
		component->draw();
	}
}


void GameSystem::handle_input() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
			switch (event.key.keysym.scancode) {
			case SDL_SCANCODE_ESCAPE:
				running = false;
				break;
			case SDL_SCANCODE_F12:
				input.rebind_key();
				break;
			case SDL_SCANCODE_0:
				Options* options = Options::create_instance(get_renderer(), UI_manager->get_active_ui_name());
				options->run();
				delete options;
				break;
			}
		}

		if (event.type == SDL_MOUSEBUTTONDOWN && event.key.repeat == 0)
			UI_manager->handle_interact({ event.button.x, event.button.y});
	}
}

void GameSystem::update_scene_objects() {

	/**************************************************************************************
	#2020-12-14:
	Koller först om scenens vektorer innehåller något som ska tas bort, i så fall
	gör vi delete här och tar bort dom ur de aktiva vektorerna.
	
	Kollar sen om något behöver läggas till (ny bullet exempelvis) och lägger till
	om något finns. 

	När allt är klart kallas scenens clear-metod så alla lägg-tll och ta-bort-vektorerer 
	är tomma när en ny frame börjar. 

	#2020-12-15:
	Gjorde en template-funktion som sköter borttagning och tillägg istället, slapp skriva
	samma for-loop för två olika typer. Tog tid på funktionen med, som snabbast var den nere på
	4 mikrosekunder när ingenting behövde läggas till och 406 mikrosekunder om man sköt konstant
	och bullets behövde tas bort.
	*************************************************************************************/

	

	update_active_vector<Sprite>(current_scene->sprites->get_removed(),
								 current_scene->sprites->get_added(), 
								 active_sprites);

	update_active_vector<Component>(current_scene->components->get_removed(),
		current_scene->components->get_added(),
		active_components);
	

	//ta bort
	for (Sprite* s : current_scene->sprites->get_removed()) {
		auto& it = std::find(collision_layers.begin(), collision_layers.end(), s);
		if (it != collision_layers.end()) {
			collision_layers.erase(it);
		}
	}

	for (Sprite* sprite : current_scene->sprites->get_added()) {
		collision_layers.push_back(sprite);
	}
	
	current_scene->components->clear_vectors();
	current_scene->sprites->clear_vectors();
}

GameSystem::~GameSystem() {}

SDL_Renderer& GameSystem::get_renderer() const {
	return *mainWindow->get_ren();
}


void GameSystem::load_new_scene(Scene* newScene, std::string UI) {
	if(!current_scene)
		delete current_scene;

	current_scene = newScene;
	

	active_components.clear();
	active_sprites.clear();
	collision_layers.clear();

	

	for (Component* component : current_scene->components->get_added())
		active_components.push_back(component);

	
	for (Sprite* sprite : current_scene->sprites->get_added()) {
		active_sprites.push_back(sprite);
		if (dynamic_cast<EnemyHandler*>(sprite)) {
			for (Enemy* e : dynamic_cast<EnemyHandler*>(sprite)->get_enemies()) {
				collision_layers.push_back(e);
			}
		}
		else
			collision_layers.push_back(sprite);
	}

	UI_manager->change_page(UI);

	game_over(0);

	current_scene->components->clear_vectors();
	current_scene->sprites->clear_vectors();
}

Scene& GameSystem::get_current_scene() const {
	return *current_scene;
}

SceneData& GameSystem::get_scene_data() const {
	return *sceneData;
}

MainWindow& GameSystem::get_current_window() const {
	return *mainWindow;
}

GameSystem gameSystem;