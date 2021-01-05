#include "Component.h"
#include <iostream>

Component::Component(SDL_Rect rect) : rect{ rect } {}

Component::~Component() {

}

const SDL_Rect& Component::get_rect() const {
	return rect;
}