#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Animator.h"
#include "Animation.h"
class Background : public Sprite
{
public:
	static Background* get_instance(int, int, int, int);
	~Background();
	void tick();
	void draw();
	void resolve_collision(){}
private:
	Background(int, int, int, int);
	Animator* anim;
	Animation* bg;
	int tickCount = 0;
};

#endif