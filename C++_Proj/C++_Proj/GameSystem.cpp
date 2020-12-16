#include "GameSystem.h"
#include "MainWindow.h"
#include <SDL.h>
#include <iostream>
#include "Input.h"
#include "Log.h"
#include <chrono>
void GameSystem::run() {


	current_scene = scene_map.begin()->second;
	
	Uint32 tickInterval = 1000 / FPS;

	while (running) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		
		SDL_RenderClear(mainWindow.get_ren());

		update_components();
		update_sprites();
		
		SDL_RenderPresent(mainWindow.get_ren());
		
		float delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);

		update_scene_objects();
		handle_input();

	}
}

void GameSystem::update_components() {
	for (Component* component : active_components) {
		component->tick();
		component->draw();
	}
}

void GameSystem::update_sprites() {
	for (Sprite* sprite : active_sprites) {
		sprite->tick();
		sprite->draw();
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
			case SDL_SCANCODE_F1:
				load_new_scene(0);
				break;
			case SDL_SCANCODE_F2:
				load_new_scene(1);
				break;
			case SDL_SCANCODE_F3:
				load_new_scene(2);
				break;
			}
		}
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

	update_active_vector<Component>(current_scene->components->get_removed(), 
									current_scene->components->get_added(),
									active_components);

	update_active_vector<Sprite>(current_scene->sprites->get_removed(),
								 current_scene->sprites->get_added(), 
								 active_sprites);

	current_scene->components->clear_vectors();
	current_scene->sprites->clear_vectors();
}

GameSystem::~GameSystem() {}


void GameSystem::load_new_scene(unsigned int scene_index) {
	auto it = scene_map.find(scene_index);

	if (it == scene_map.end()) {
		LOG("Could not load scene, no such index");
		return;
	}

	//FÖRSTÖR INTE GAMLA OBJEKT ANNARS BLIR DET JÄÄÄVLIGT SVÅRT ATT LADDA OM EN ANNAN SCEN

	//Rensar aktiva objekt, datan finns ju sparad i respektive scen-objekt

	/****************************
	* Måste hitta ett sätt att resetta en scen, laddar man in en scen som redan har körts en gång
	* renderas sprites på samma plats som de var på när scenen byttes ut eftersom den gamla scenens pekarna fortfarande
	* finns i minnet.
	****************************/

	active_components.clear();
	active_sprites.clear();

	for (Component* component : it->second->components->get_added()) 
		active_components.push_back(component);
	
	for (Sprite* sprite : it->second->sprites->get_added())
		active_sprites.push_back(sprite);



	current_scene->components->clear_vectors();
	current_scene->sprites->clear_vectors();
}

void GameSystem::add_new_scenes(std::initializer_list<Scene*> new_scenes) {
	for(Scene* scene : new_scenes)
		scene_map.insert(std::pair<unsigned int, Scene*>(scene->get_scene_index(), scene));
}

void GameSystem::add_new_scene(Scene* new_scene) {
	scene_map.insert(std::pair<unsigned int, Scene*>(new_scene->get_scene_index(), new_scene));
}

Scene* GameSystem::get_current_scene() {
	return current_scene;
}

GameSystem gameSystem;