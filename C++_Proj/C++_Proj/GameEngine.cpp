#include "GameEngine.h"
#include <SDL.h>
#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void GameEngine::add_component(Component* component) {
	components.push_back(component);
	LOG("La till!");
	LOG(components.size());
}

/*
* Kallar delete på alla componenter, tror inte det räcker med bara empty.
*/
void GameEngine::remove_all_components() {
	LOG(components.size());
	for (int i = 0; i < components.size(); i++) {
		Component* c = components[i];
		components.erase(components.begin() + i);
		delete c;
	}
		
	LOG(components.size());
}

void GameEngine::run() {
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

		//SetRenderClear(renderer);
		/*for (Component* component : components)
			component->draw();
		*/
		//SDL_RenderPresent(renderer);

	}//yttre while
}

GameEngine::~GameEngine() {}