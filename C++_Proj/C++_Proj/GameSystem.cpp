#include "GameSystem.h"
#include "MainWindow.h"
#include <SDL.h>

void GameSystem::add_component(Component* component) {
	components.push_back(component);
}

void GameSystem::add_sprites(Sprite* sprite) {
	sprites.push_back(sprite);
}

void GameSystem::run() {
	bool run = true;

	Uint32 tickInterval = 1000 / FPS;

	while (run) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				run = false;
				break;
			}
		}

		SDL_RenderClear(mainWindow.get_ren());

		update_components();
		update_sprites();

		SDL_RenderPresent(mainWindow.get_ren());

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	}
}

void GameSystem::update_components() {
	for (Component* component : components) {
		//component->tick();
		component->draw();
	}
		
}

void GameSystem::update_sprites() {
	for (Sprite* sprite : sprites) {
		sprite->tick();
		sprite->draw();
	}

}


GameSystem::~GameSystem() {}

GameSystem gameSystem;