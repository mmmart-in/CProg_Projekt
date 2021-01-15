#include "Animation.h"
#include "GameSystem.h"




Animation::Animation(std::initializer_list<std::string> images) {
	for (std::string im : images) {
		SDL_Surface* surf = IMG_Load(im.c_str());
		SDL_Texture* textur = SDL_CreateTextureFromSurface(&gameSystem.get_renderer(), surf);
		SDL_FreeSurface(surf);

		texts.push_back(textur);
	}
}

Animation::~Animation() {
	for (SDL_Texture* t : texts) {
		SDL_DestroyTexture(t);
	}
	texts.clear();
}

SDL_Texture* Animation::get_texture_at(int i) {
	return texts[i];
}

int Animation::get_size() {
	return texts.size();
}