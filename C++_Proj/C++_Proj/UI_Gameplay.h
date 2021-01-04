#pragma once
#include "UI_Page.h"
#include "EnemyHandler.h"

class UI_Gameplay : public UI_Page {
public:
	static UI_Gameplay* create_instance();
	void interact_with(UI_Button*) {}
private:
	UI_Gameplay() = default;
};

