#include "UI_Component.h"

UI_Component::UI_Component(SDL_Rect rect) :rect(rect) {
}

const SDL_Rect& UI_Component::get_rect() const{ 
	return rect;
}
