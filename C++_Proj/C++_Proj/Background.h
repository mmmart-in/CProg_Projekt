#pragma once
#include "FixedSprite.h"
#include "Animator.h"
#include "Animation.h"
class Background : public FixedSprite
{
public:
	Background(int, int, int, int);
private:
	Animator* anim;
};
