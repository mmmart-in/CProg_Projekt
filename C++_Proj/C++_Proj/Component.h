#pragma once

#include <SDL.h>

class Component {

public:
	~Component();
	virtual void draw() const = 0;
	virtual void tick() = 0;
	const SDL_Rect& get_rect() const;
protected:
	Component(int, int, int, int);
private:
	SDL_Rect rect;
	Component(const Component&) = delete;
	const Component& operator=(const Component&) = delete;
};

