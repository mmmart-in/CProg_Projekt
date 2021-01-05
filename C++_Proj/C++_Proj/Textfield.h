#pragma once

#include <string>
#include "Component.h"

class Textfield : public Component {
public:
	static Textfield* create_instance(SDL_Rect, SDL_Color);
	void tick() override {}
	void draw() const override;
	void run();
private:
	Textfield(SDL_Rect, SDL_Color);
	SDL_Color color;
	std::string text;
	bool has_focus = false;
};

