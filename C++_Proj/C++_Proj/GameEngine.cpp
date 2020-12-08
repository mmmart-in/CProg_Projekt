#include "GameEngine.h"
#include <SDL.h>
void GameEngine::add_component(Component* component) {
	components.push_back(component);
}

/*
* Kallar delete på alla componenter, tror inte det räcker med bara empty.
*/
void GameEngine::remove_component(Component* component) {
	for (int i = 0; i < components.size(); i++)
		if (components[i] = component) {
			components.erase(components.begin() + i);
			delete component;
		}	
}

/*
* Kallar delete på alla componenter, tror inte det räcker med bara empty.
*/
void GameEngine::remove_all_components() {
	for (int i = 0; i < components.size(); i++) 
		delete components[i];
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