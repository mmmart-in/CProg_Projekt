#pragma once
#include "UI_Button.h"
class Button_Options : public UI_Button {
public:
	Button_Options(SDL_Rect, std::string, SDL_Color, std::string);
	void invoke() override;
};

