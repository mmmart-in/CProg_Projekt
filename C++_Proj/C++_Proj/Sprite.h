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
	void set_layer(int x) { layer = x; }
	void set_tag(std::string x) { tag = x; }
	SDL_Rect& get_rect();
protected:
	Sprite(int x, int y, int w, int h);
	
private:
	Sprite(const Sprite&) = delete;
	const Sprite& operator=(const Sprite&) = delete;
	SDL_Rect rect;
	Collider* collider;
	int layer;
	std::string tag;
};

