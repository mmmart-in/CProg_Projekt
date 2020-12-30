#include "Label.h"
#include <SDL_ttf.h>
#include "MainWIndow.h"


Label* Label::getInstance(int x, int y, int w, int h, std::string txt, SDL_Color textColor) {
	return new Label(x, y, w, h, txt, textColor);
}

Label::Label(int x, int y, int w, int h, std::string text, SDL_Color textColor) : Component(x, y, w, h), text(text), textColor(textColor){
	SDL_Surface* surf = TTF_RenderText_Solid(mainWindow.get_font(), text.c_str(), textColor);
	texture = SDL_CreateTextureFromSurface(mainWindow.get_ren(), surf);
	SDL_FreeSurface(surf);
}

void Label::draw() const {
	SDL_RenderCopy(mainWindow.get_ren(), texture, NULL, &get_rect());
}

void Label::tick() {
}

Label::~Label() {
	SDL_DestroyTexture(texture);
}

std::string Label::getText() const {
	return text;
}
void Label::setText(std::string newText) {
	text = newText;
	SDL_DestroyTexture(texture);
	SDL_Surface* surf = TTF_RenderText_Solid(mainWindow.get_font(),
		text.c_str(), textColor);
	texture = SDL_CreateTextureFromSurface(mainWindow.get_ren(), surf);
	SDL_FreeSurface(surf);
}