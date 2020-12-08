#include "Sprite.h"
#include <SDL_image.h>
#include "MainWindow.h"


Sprite::Sprite(int x, int y, int w, int h, std::string image) : 
	rect{ x, y, w, h } 
{
	//fuskimplementation för test
	SDL_Surface* surf = IMG_Load(image.c_str());
	texture = SDL_CreateTextureFromSurface(mainWindow.get_ren(), surf);
	SDL_FreeSurface(surf);
	SDL_RenderCopy(mainWindow.get_ren(), texture, NULL, &rect);
};

Sprite::~Sprite(){}

