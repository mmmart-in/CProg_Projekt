#include "Sprite.h"
#include <SDL_image.h>
#include "MainWindow.h"

Sprite::Sprite(int x, int y, int w, int h) : 
	rect{ x, y, w, h } 
{
	//fuskimplementation för test
	SDL_Surface* alien = IMG_Load("C:/resources/alien.png");
	texture = SDL_CreateTextureFromSurface(mainWindow.get_ren(), alien);
	SDL_FreeSurface(alien);
	SDL_RenderCopy(mainWindow.get_ren(), texture, NULL, &rect);
};

Sprite::~Sprite(){}

