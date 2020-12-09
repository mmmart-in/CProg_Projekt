#include "GameSystem.h"
#include "MainWindow.h"
#include <SDL.h>
#include <iostream>
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
void GameSystem::add_component(Component* component) {
	components.push_back(component);
}

void GameSystem::add_sprites(Sprite* sprite) {
	sprites.push_back(sprite);
	std::cout << "Added!" << sprite;
}

void GameSystem::run() {
	bool run = true;

	Uint32 tickInterval = 1000 / FPS;

	while (run) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval; //Antal millisekunder tills n�sta loop ska ske
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

		//nextTick - millisekunder sedan nextTick, positivt = loopen var f�r snabb, v�nta in tills nextTick
		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
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

<<<<<<< Updated upstream
GameSystem::~GameSystem() {}
=======
GameSystem::~GameSystem() {}

GameSystem gameSystem;
>>>>>>> Stashed changes
