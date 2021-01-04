#pragma once
#include "Animation.h"
#include "Animator.h"
#include <vector>

class Health
{
public:
	Health(int);
	void get_hit();
	void draw();
private:
	int hitCount;
	Animator* anim;
	std::vector<Animation> lives;

};

