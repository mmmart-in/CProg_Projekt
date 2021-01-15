#pragma once

#include <string>
#include "UI_Component.h"
#include "UI_Label.h"
class UI_Textfield : public UI_Component {
public:
	static UI_Textfield* create_instance(SDL_Rect, SDL_Color, std::string);
	void tick() override {}
	void draw() override;
	void interact() override;
	void run();
	~UI_Textfield() {}
private:
	UI_Textfield(SDL_Rect, SDL_Color, std::string);
	SDL_Color color;
	SDL_Texture* texture;
	std::string text;
	SDL_Rect write_rect;
	int text_size = 32;
	bool has_focus = false;

};

