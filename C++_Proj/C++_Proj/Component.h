#pragma once

#include <SDL.h>

class Component {

public:
	~Component();
	//virtual void draw() const = 0;
	const SDL_Rect& get_rect() const;
	Component(int, int, int, int);
protected:
	
private:
	SDL_Rect rect;
	Component(const Component&) = delete;
	const Component& operator=(const Component&) = delete;
};

