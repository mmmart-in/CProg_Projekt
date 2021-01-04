#include "Health.h"

Health::Health(int h) :
	hitCount(h)
{
	for (int i = 0; i <= h; i++) {

	}


	anim = new Animator(lives);
}