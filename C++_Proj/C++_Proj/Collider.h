#pragma once
#include <SDL.h>
struct Collider
{
	Collider(int x, int y, int w, int h);
	~Collider();
	bool check_collision(const Collider&);
	int x, y, w, h;
};

