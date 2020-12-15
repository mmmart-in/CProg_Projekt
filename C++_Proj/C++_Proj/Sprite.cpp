#include "Sprite.h"
#include <SDL_image.h>
#include "MainWindow.h"


Sprite::Sprite(int x, int y, int w, int h) : 
	rect{ x, y, w, h } 
{
	
};


const SDL_Rect& Sprite::get_rect() const {
	return rect;
}

Sprite::~Sprite(){}

