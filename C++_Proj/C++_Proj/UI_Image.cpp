#include "UI_Image.h"
#include "GameSystem.h"

UI_Image* UI_Image::get_instance(SDL_Rect rect, std::string image) {
	return new UI_Image(rect, image);
}

UI_Image* UI_Image::get_instance(SDL_Rect rect, SDL_Texture* texture) {
	return new UI_Image(rect, texture);
}



UI_Image::UI_Image(SDL_Rect rect, std::string image) : UI_Component(rect)
{
	SDL_Surface* surf = IMG_Load(image.c_str());
	texture = SDL_CreateTextureFromSurface(gameSystem.get_current_window().get_ren(), surf);
	SDL_FreeSurface(surf);
}

UI_Image::UI_Image(SDL_Rect rect, SDL_Texture* texture) : UI_Component(rect), texture(texture) {}

void UI_Image::tick(){}

void UI_Image::draw()  {
	SDL_RenderCopy(gameSystem.get_current_window().get_ren(), texture, NULL, &get_rect());
}

UI_Image::~UI_Image() {
	SDL_DestroyTexture(texture);
}
