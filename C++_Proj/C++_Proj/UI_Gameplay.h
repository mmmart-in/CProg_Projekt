#pragma once
#include "UI_Page.h"
#include "EnemyHandler.h"
#include <string>

class UI_Gameplay : public UI_Page {
public:
	static UI_Gameplay* create_instance(std::string);
	void interact_with(Component*) {}
private:
	UI_Gameplay(std::string);
};

