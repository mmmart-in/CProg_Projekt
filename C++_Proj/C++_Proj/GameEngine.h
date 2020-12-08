#pragma once

#include <vector>
#include "Component.h"

class GameEngine {

public:
	void add_component(Component*);
	void remove_component(Component*);
	void remove_all_components();
	void run();
	~GameEngine();

private:
	std::vector<Component*> components;
};

