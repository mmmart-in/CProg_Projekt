#include "Sprite.h"
#include <SDL_image.h>
#include "MainWindow.h"



Sprite::Sprite(int x, int y, int w, int h) : 
	rect{ x, y, w, h } 
{

	collider = new Collider(x, y, w, h);
};


SDL_Rect& Sprite::get_rect(){
	return rect;
}

Sprite::~Sprite() {
	delete collider;
}

