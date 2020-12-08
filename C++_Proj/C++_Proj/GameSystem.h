#pragma once
#include <vector>
#include "Component.h"
#include "Sprite.h"
class GameSystem
{
	public:
		void add_component(Component*);
		void add_sprites(Sprite*);
		void run();
		~GameSystem();

	private:
		std::vector<Component*> components;
		std::vector<Sprite*> sprites;


};

