#pragma once
#include <SDL.h>
#include <string>

class Sprite
{
public:
	virtual ~Sprite();
	virtual void tick() = 0;
	virtual void draw() = 0;
protected:
	Sprite(int x, int y, int w, int h, std::string image);
	SDL_Texture* texture;
private:
	SDL_Rect rect;
};

