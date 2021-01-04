#pragma once
#include "Animator.h"
#include "Animation.h"
class Background : public Sprite
{
public:
	Background(int, int, int, int);
private:
	Animator* anim;
};
