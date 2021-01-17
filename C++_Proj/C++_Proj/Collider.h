#pragma once
#include <SDL.h>
struct Collider
{
	Collider(int x, int y, int w, int h);
	bool check_collision(const Collider&);
	int& getX() { return x; }
	int& getY() { return y; }
private:
	int x, y, w, h;
};

