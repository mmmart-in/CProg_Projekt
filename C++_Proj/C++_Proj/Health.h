#ifndef HEALTH_H
#define HEALTH_H


#include <SDL_image.h>
#include <vector>
#include "UI_Image.h"

class Health
{
public:
	static Health* get_instance(int);
	~Health();
	void get_hit();
	void draw();
	void tick();
private:
	Health(int);
	int hits, MAXhits;
	std::vector<UI_Image*> lives;
};

#endif
