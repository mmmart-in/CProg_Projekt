#include "UI_Image.h"
#include "GameSystem.h"

UI_Image* UI_Image::get_instance(SDL_Rect rect, std::string image) {
	return new UI_Image(rect, image);
}

UI_Image::UI_Image(SDL_Rect rect, std::string image) : Component(rect)
{
	SDL_Surface* surf = IMG_Load(image.c_str());
	texture = SDL_CreateTextureFromSurface(gameSystem.get_current_window().get_ren(), surf);
	SDL_FreeSurface(surf);
}

void UI_Image::tick(){}

void UI_Image::draw() const {
	SDL_RenderCopy(gameSystem.get_current_window().get_ren(), texture, NULL, &get_rect());
}