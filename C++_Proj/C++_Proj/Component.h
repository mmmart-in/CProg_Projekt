#ifndef COMPONENT_H
#define COMPONENT_H


#include <SDL.h>

class Component {

public:
	virtual ~Component();
	virtual void draw() const = 0;
	virtual void tick() = 0;
	const SDL_Rect& get_rect() const;
protected:
	Component(SDL_Rect);
private:
	SDL_Rect rect;
	Component(const Component&) = delete;
	const Component& operator=(const Component&) = delete;
};

#endif