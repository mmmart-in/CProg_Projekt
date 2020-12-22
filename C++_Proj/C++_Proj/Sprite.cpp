#include "Sprite.h"
#include <SDL_image.h>
#include "MainWindow.h"


Sprite::Sprite(int x, int y, int w, int h) : 
	rect{ x, y, w, h } 
{
	collider = new Collider(x, y, w-2, h-2);
};


const SDL_Rect& Sprite::get_rect() const {
	return rect;
}

int Sprite::get_layer() {
	return layer;
}
Sprite::~Sprite(){}

