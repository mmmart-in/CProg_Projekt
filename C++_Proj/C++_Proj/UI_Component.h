#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H

#include "Component.h"

class UI_Component {
public:
	UI_Component(SDL_Rect);
	virtual ~UI_Component() {}
	virtual void tick() = 0;
	virtual void draw() = 0;
	virtual void interact() = 0;
	const SDL_Rect& get_rect() const;
private:
	SDL_Rect rect;
};

#endif