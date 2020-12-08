#include "Component.h"
#include <iostream>

Component::Component(int x, int y, int w, int h) : rect{ x, y, w, h } {}

Component::~Component() {
	std::cout << "Removed " << this << std::endl;
}

const SDL_Rect& Component::get_rect() const {
	return rect;
}