#include "Component.h"
#include <iostream>

Component::Component(SDL_Rect rect) : rect{ rect } {}

Component::~Component() {
	std::cout << "Removed " << this << std::endl;
}

const SDL_Rect& Component::get_rect() const {
	return rect;
}