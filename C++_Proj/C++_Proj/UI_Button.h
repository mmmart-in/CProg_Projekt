#pragma once

#include "UI_Component.h"
#include <string>
#include "UI_Label.h"
#include <iostream>
#include "EventSubject.h"

class UI_Button : public UI_Component {

public:
	UI_Button(SDL_Rect, std::string, SDL_Color, std::string);
	~UI_Button() override;
	void tick() override {};
	void draw() override;
	void interact() override {}
	inline std::string get_button_name() const { return button_name; }
private:
	std::string button_name;
	bool hovering_over;
	bool is_pressed;
	SDL_Texture* hovering;
	SDL_Texture* pressed;
	SDL_Texture* regular;
	SDL_Texture* showing;
	UI_Label* label;
};



