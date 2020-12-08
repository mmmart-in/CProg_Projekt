#pragma once
#include <SDL.h>

class Sprite
{
public:
	virtual ~Sprite();
	virtual void tick() = 0;
	virtual void draw() = 0;

protected:
	Sprite(int x, int y, int w, int h);
	SDL_Texture* texture;
private:
	SDL_Rect rect;
};

