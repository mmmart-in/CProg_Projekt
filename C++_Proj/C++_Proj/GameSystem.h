#pragma once
#include <vector>
#include "Component.h"
class GameSystem
{
	public:
		void add_component(Component*);
		void remove_component(Component*);
		void remove_all_components();
		void run();
		~GameSystem();

	private:
		std::vector<Component*> components;


};

