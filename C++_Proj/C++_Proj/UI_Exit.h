#pragma once
#include "UI_Button.h"
class UI_Exit : public UI_Button {
public:
	static UI_Exit* create_instance(SDL_Rect, std::string, SDL_Color, std::string);
	void interact() override;
private:
	UI_Exit(SDL_Rect, std::string, SDL_Color, std::string);
};