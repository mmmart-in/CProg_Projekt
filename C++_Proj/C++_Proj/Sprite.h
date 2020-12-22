#pragma once
#include <SDL.h>
#include <string>
#include "Collider.h"

class Sprite
{
public:
	virtual ~Sprite();
	virtual void tick() = 0;
	virtual void draw() = 0;
	virtual Collider* get_collider() = 0;
	virtual void resolve_collision() = 0;
	int get_layer();
	const SDL_Rect& get_rect() const;
protected:
	Sprite(int x, int y, int w, int h);
	SDL_Rect rect;
	Collider* collider;
	int layer;
private:
	
};

