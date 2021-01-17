#pragma once
#include "UI_Button.h"
class UI_HowToPlay : public UI_Button {
public:
	static UI_HowToPlay* create_instance(SDL_Rect, std::string, SDL_Color, std::string);
	void interact() override;
private:
	UI_HowToPlay(SDL_Rect, std::string, SDL_Color, std::string);
};

