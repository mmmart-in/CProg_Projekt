#ifndef COLLIDER_H
#define COLLIDER_H


#include <SDL.h>
struct Collider
{
	Collider(int x, int y, int w, int h);
	bool check_collision(const Collider&);
	int x, y, w, h;
};

#endif