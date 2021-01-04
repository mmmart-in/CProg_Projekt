#pragma once

#include "Component.h"
#include <string>
#include "Label.h"
#include <iostream>
#include "EventSubject.h"

struct Function {};

class UI_Button : public Component, public EventSubject {

public:
	UI_Button(int, int, int, int, SDL_Texture*, SDL_Texture*, SDL_Texture*, std::string, SDL_Color, std::string);
	~UI_Button();
	void tick() override {};
	void draw() const override;
	void set_pressed(bool) const;
	inline std::string get_button_name() const { return button_name; }
private:
	std::string button_name;
	bool hovering_over;
	bool is_pressed;
	SDL_Texture* hovering;
	SDL_Texture* pressed;
	SDL_Texture* regular;
	SDL_Texture* showing;

	Label* label;
};



