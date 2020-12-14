#include "GameSystem.h"
#include "MainWindow.h"
#include <SDL.h>
#include <iostream>
#include "Input.h"

void GameSystem::add_component(Component* component) {
	components.push_back(component);
}

void GameSystem::add_sprites(Sprite* sprite) {
	sprites.push_back(sprite);
}

/*void GameSystem::add_to_temp(Sprite* sprite) {
	temp.push_back(sprite);
}*/
void GameSystem::run() {

	Uint32 tickInterval = 1000 / FPS;

	while (running) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		
		SDL_RenderClear(mainWindow.get_ren());
		
		
		update_components();
		update_sprites();
		
		/*for (Sprite* s : temp)
			add_sprites(s);
		temp.clear();*/

		SDL_RenderPresent(mainWindow.get_ren());

		float delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);

		handle_input();
	}
}

void GameSystem::update_components() {
	for (int i = 0; i < components.size(); i++) {
		components[i]->tick();
		components[i]->draw();
	}
}

void GameSystem::update_sprites() {
	for (int i = 0; i < sprites.size(); i++) {
		sprites[i]->tick();
		sprites[i]->draw();
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
			case SDL_SCANCODE_F1:
				input.rebind_key();
				break;
			}
		}
	}
}

GameSystem::~GameSystem() {}

GameSystem gameSystem;