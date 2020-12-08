#include "GameSystem.h"
#include "MainWindow.h"
#include <SDL.h>

void GameSystem::add_component(Component* component) {
	components.push_back(component);
}

void GameSystem::run() {
	bool run = true;
	while (run) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				run = true;
				break;
			}
		}//inre while

		SDL_RenderClear(mainWindow.get_ren());
		for (Component* component : components)
			component->draw();

		SDL_RenderPresent(mainWindow.get_ren());

	}//yttre while
}
