#pragma once
#include "UI_Page.h"
#include "UI_Button.h"
class UI_Menu : public UI_Page {
public:
	void interact_with(UI_Button*) override;
};

