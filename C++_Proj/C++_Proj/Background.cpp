#include "Background.h"


Background::Background(int x, int y, int w, int h) : FixedSprite(x, y, w, h){


	Animation bg{};
	anim = new Animator{};

}