#include "UI_Image.h"
#include "GameSystem.h"

UI_Image* UI_Image::get_instance(int x, int y, int w, int h, std::string image) {
	return new UI_Image(x, y, w, h, image);
}

UI_Image::UI_Image(int x, int y, int w, int h, std::string image) :
	Component(x, y, w, h)
{
	SDL_Surface* surf = IMG_Load(image.c_str());
	texture = SDL_CreateTextureFromSurface(gameSystem.get_current_window().get_ren(), surf);
	SDL_FreeSurface(surf);
}

void UI_Image::tick(){}

void UI_Image::draw() const{
	SDL_RenderCopy(gameSystem.get_current_window().get_ren(), texture, NULL, &get_rect());
}