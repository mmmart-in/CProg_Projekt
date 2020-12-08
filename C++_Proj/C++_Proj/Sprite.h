#pragma once
#include <SDL.h>

class Sprite
{
public:
	virtual void tick() = 0;
	virtual void draw() = 0;
	

protected:
	Sprite(int x, int y, int w, int h);
	~Sprite();

private:
	SDL_Rect rect;
	//SDL_Texture* txtur;

	
};

