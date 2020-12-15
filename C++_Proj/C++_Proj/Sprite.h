#pragma once
#include <SDL.h>
#include <string>

class Sprite
{
public:
	virtual ~Sprite();
	virtual void tick() = 0;
	virtual void draw() = 0;
	const SDL_Rect& get_rect() const;
protected:
	Sprite(int x, int y, int w, int h);
	SDL_Rect rect;
	
private:
	
};

