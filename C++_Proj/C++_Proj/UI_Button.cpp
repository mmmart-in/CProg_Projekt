#include "UI_Button.h"
#include "GameSystem.h"


UI_Button::UI_Button(SDL_Rect rect, std::string text, SDL_Color color, std::string button_name) :
	Component(rect), label(Label::getInstance(rect, text, color)), regular(regular), hovering(hovering), pressed(pressed), showing(0), button_name(button_name) {}

UI_Button::~UI_Button() {
	SDL_DestroyTexture(hovering);
	SDL_DestroyTexture(pressed);
	SDL_DestroyTexture(regular);
	SDL_DestroyTexture(showing);
	delete label;
}


void UI_Button::draw() const {
	if (!regular)
		label->draw();
	else 
		SDL_RenderCopy(&gameSystem.get_renderer(), is_pressed ? pressed : hovering_over ? hovering : regular, NULL, &get_rect());
}


void UI_Button::set_pressed(bool pressed) const {

}

