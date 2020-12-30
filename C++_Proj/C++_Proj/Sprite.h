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
	Collider* get_collider() { return collider; }
	virtual void resolve_collision() = 0;
	std::string get_tag() { return tag; }
	int get_layer() { return layer; }
	const SDL_Rect& get_rect() const;
protected:
	Sprite(int x, int y, int w, int h);
	SDL_Rect rect;
	Collider* collider;
	int layer;
	std::string tag;
private:
	
};

