#include "Label.h"
#include <SDL_ttf.h>
#include "MainWIndow.h"


Label* Label::getInstance(int x, int y, int w, int h, std::string txt) {
	return new Label(x, y, w, h, txt);
}

Label::Label(int x, int y, int w, int h,
	std::string txt) : Component(x, y, w, h), text(txt)
{
	SDL_Surface* surf = TTF_RenderText_Solid(mainWindow.get_font(), text.c_str(), {0, 0, 0});
	texture = SDL_CreateTextureFromSurface(mainWindow.get_ren(), surf);
	SDL_FreeSurface(surf);
}

void Label::draw() const {
	SDL_RenderCopy(mainWindow.get_ren(), texture, NULL, &get_rect());
}

Label::~Label()
{
	SDL_DestroyTexture(texture);
}

std::string Label::getText() const {
	return text;
}
void Label::setText(std::string newText) {
	text = newText;
	SDL_DestroyTexture(texture);
	SDL_Surface* surf = TTF_RenderText_Solid(mainWindow.get_font(),
		text.c_str(), { 0,0,0 });
	texture = SDL_CreateTextureFromSurface(mainWindow.get_ren(), surf);
	SDL_FreeSurface(surf);
}