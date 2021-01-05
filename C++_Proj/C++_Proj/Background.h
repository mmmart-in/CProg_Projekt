#pragma once
#include "Animator.h"
#include "Animation.h"
class Background : public Sprite
{
public:
	static Background* get_instance(int, int, int, int);
	void tick();
	void draw();
	void resolve_collision(){}
private:
	Background(int, int, int, int);
	Animator* anim;
	int tickCount = 0;
};
