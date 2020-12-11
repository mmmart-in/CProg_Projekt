#pragma once
#include <vector>
#include "Component.h"
#include "Sprite.h"

#define FPS 60

class GameSystem {
	public:
		void add_component(Component*);
		void add_sprites(Sprite*);
		//void add_to_temp(Sprite*);
		void run();
		~GameSystem();
		bool running = true;
	private:
		void update_components();
		void update_sprites();
		void handle_input();
		std::vector<Component*> components;
		std::vector<Sprite*> sprites;
		std::vector<Sprite*> temp;
};

extern GameSystem gameSystem;

