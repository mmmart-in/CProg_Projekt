#include "UI_Label.h"
#include <SDL_ttf.h>
#include <iostream>
#include "GameSystem.h"


UI_Label* UI_Label::getInstance(SDL_Rect rect, std::string txt, SDL_Color textColor) {
	return new UI_Label(rect, txt, textColor);
}

UI_Label::UI_Label(SDL_Rect rect, std::string text, SDL_Color textColor) : UI_Component(rect), text(text), textColor(textColor){
	SDL_Surface* surf = TTF_RenderText_Solid(gameSystem.get_current_window().get_font(), text.c_str(), textColor);
	texture = SDL_CreateTextureFromSurface(&gameSystem.get_renderer(), surf);
	SDL_FreeSurface(surf);
}

void UI_Label::draw() {
	SDL_RenderCopy(&gameSystem.get_renderer(), texture, NULL, &get_rect());
}


UI_Label::~UI_Label() {
	SDL_DestroyTexture(texture);
}

std::string UI_Label::getText() const {
	return text;
}
void UI_Label::setText(std::string newText) {
	text = newText;
	SDL_DestroyTexture(texture);
	SDL_Surface* surf = TTF_RenderText_Solid(gameSystem.get_current_window().get_font(), text.c_str(), textColor);
	texture = SDL_CreateTextureFromSurface(&gameSystem.get_renderer(), surf);
	SDL_FreeSurface(surf);
}


const SDL_Texture* UI_Label::get_texture() const {
	return texture;
}
