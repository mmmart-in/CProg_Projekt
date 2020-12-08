#pragma once
#include <vector>
#include "Component.h"
#include "Sprite.h"

#define FPS 60

class GameSystem {
	public:
		void add_component(Component*);
		void add_sprites(Sprite*);
		void run();
		~GameSystem();

	private:
		void update_components();
		void update_sprites();
		std::vector<Component*> components;
		std::vector<Sprite*> sprites;
};

