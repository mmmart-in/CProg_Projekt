#pragma once
#include <SDL_image.h>
#include <vector>
#include "UI_Image.h"

class Health
{
public:
	Health(int);
	void get_hit();
	void draw();
	void tick();
private:
	int hits, MAXhits;
	std::vector<UI_Image*> lives;

};

