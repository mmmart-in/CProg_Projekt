#pragma once

#include "UI_Page.h"
#include <string>
class UI_Options : public UI_Page {
public:
	UI_Options(std::string);
	void interact_with(Component*) override;
};

