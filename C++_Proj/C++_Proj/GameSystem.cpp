#include "GameSystem.h"
#include "MainWindow.h"
#include <SDL.h>
#include <iostream>
#include "Input.h"
#include "Log.h"
#include <chrono>
#include "SceneData.h"
#include "EnemyHandler.h"
void GameSystem::run() {
	deltaTime = 0;

	current_scene = sceneData.load_menu();
	
	Uint32 tickInterval = 1000 / FPS;

	while (running) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		

		SDL_RenderClear(mainWindow.get_ren());

		update_components();
		update_sprites();
		
		SDL_RenderPresent(mainWindow.get_ren());
		
		deltaTime = nextTick - SDL_GetTicks();
		if (deltaTime > 0)
			SDL_Delay(deltaTime);

		
		update_scene_objects();
		handle_input();
		//check_collision();

	}
}

void GameSystem::check_collision() {
	for (int i = 0; i < active_sprites.size(); i++) {
		for (int j = 0; j < active_sprites.size(); j++) {
			if (j == i)
				continue;
			/*if (active_sprites[i]->get_collider()->check_collision(*active_sprites[j]->get_collider()))
				active_sprites[i]->resolve_collision();*/
		}
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
				load_new_scene(sceneData.load_menu());
				break;
			case SDL_SCANCODE_F2:
				load_new_scene(sceneData.load_gameplay(3, 5));
				break;
			case SDL_SCANCODE_F3:
				load_new_scene(sceneData.load_gameplay(11, 15));
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


void GameSystem::load_new_scene(Scene* newScene) {
	delete current_scene;

	current_scene = newScene;
	

	active_components.clear();
	active_sprites.clear();

	

	for (Component* component : current_scene->components->get_added())
		active_components.push_back(component);
	
	for (Sprite* sprite : current_scene->sprites->get_added())
		active_sprites.push_back(sprite);



	current_scene->components->clear_vectors();
	current_scene->sprites->clear_vectors();
}



Scene* GameSystem::get_current_scene() {
	return current_scene;
}

GameSystem gameSystem;