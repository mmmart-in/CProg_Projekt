#include "Animation.h"

Animation::Animation(std::initializer_list<std::string> images) {
	for (std::string im : images) {
		SDL_Surface* surf = IMG_Load(im.c_str());
		SDL_Texture* textur = SDL_CreateTextureFromSurface(mainWindow.get_ren(), surf);
		SDL_FreeSurface(surf);

		texts.push_back(textur);
	}
}