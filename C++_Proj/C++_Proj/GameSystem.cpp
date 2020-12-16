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
	Koller f�rst om scenens vektorer inneh�ller n�got som ska tas bort, i s� fall
	g�r vi delete h�r och tar bort dom ur de aktiva vektorerna.
	
	Kollar sen om n�got beh�ver l�ggas till (ny bullet exempelvis) och l�gger till
	om n�got finns. 

	N�r allt �r klart kallas scenens clear-metod s� alla l�gg-tll och ta-bort-vektorerer 
	�r tomma n�r en ny frame b�rjar. 

	#2020-12-15:
	Gjorde en template-funktion som sk�ter borttagning och till�gg ist�llet, slapp skriva
	samma for-loop f�r tv� olika typer. Tog tid p� funktionen med, som snabbast var den nere p�
	4 mikrosekunder n�r ingenting beh�vde l�ggas till och 406 mikrosekunder om man sk�t konstant
	och bullets beh�vde tas bort.
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

	//F�RST�R INTE GAMLA OBJEKT ANNARS BLIR DET J���VLIGT SV�RT ATT LADDA OM EN ANNAN SCEN

	//Rensar aktiva objekt, datan finns ju sparad i respektive scen-objekt

	/****************************
	* M�ste hitta ett s�tt att resetta en scen, laddar man in en scen som redan har k�rts en g�ng
	* renderas sprites p� samma plats som de var p� n�r scenen byttes ut eftersom den gamla scenens pekarna fortfarande
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