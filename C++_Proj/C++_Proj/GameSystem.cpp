#include "GameSystem.h"
#include "MainWindow.h"
#include <SDL.h>
#include <iostream>
#include "Input.h"
#include "Log.h"

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
				load_new_scene(1);
				break;
			case SDL_SCANCODE_F2:
				load_new_scene(2);
				break;
			}
		}
	}
}

void GameSystem::update_scene_objects() {

	/**************************************************************************************
	Koller först om scenens vektorer innehåller något som ska tas bort, i så fall
	gör vi delete här och tar bort dom ur de aktiva vektorerna.
	
	Kollar sen om något behöver läggas till (ny bullet exempelvis) och lägger till
	om något finns. 

	När allt är klart kallas scenens clear-metod så alla lägg-tll och ta-bort-vektorerer 
	är tomma när en ny frame börjar. 
	*************************************************************************************/

	if (current_scene->removed_components_size() > 0) {
		
		for (Component* component : current_scene->get_removed_components()) {
			auto it = std::find(active_components.begin(), active_components.end(), component);
			if (it != active_components.end()) {
				delete *it;
				active_components.erase(it);
			}
				
		}
	}

	if (current_scene->removed_sprites_size() > 0) {

		for (Sprite* sprite : current_scene->get_removed_sprites()) {
			auto it = std::find(active_sprites.begin(), active_sprites.end(), sprite);
			if (it != active_sprites.end()) {
				delete* it;
				active_sprites.erase(it);
			}
		}
	}
		
	if (current_scene->new_components_size() > 0) 
		for (Component* new_component : current_scene->get_added_components())
			active_components.push_back(new_component);

	if (current_scene->new_sprites_size() > 0)
		for (Sprite* new_sprite : current_scene->get_added_sprites())
			active_sprites.push_back(new_sprite);
			
	current_scene->clear_vectors();
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
	active_components.clear();
	active_sprites.clear();
	
	for (Component* component : it->second->get_added_components())
		active_components.push_back(component);
		
	for (Sprite* sprite : it->second->get_added_sprites())
		active_sprites.push_back(sprite);

	current_scene = it->second;

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