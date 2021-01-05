#pragma once
#include "UI_Page.h"
#include "UI_Button.h"
class UI_Menu : public UI_Page {
public:
	UI_Menu(std::string);
	void interact_with(Component*) override;
};

