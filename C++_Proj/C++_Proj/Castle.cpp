#include "Castle.h"
#include "GameSystem.h"
#include <iostream>
#include "AudioHandler.h"
Castle* Castle::get_instance(int x, int y, int w, int h) {
	return new Castle(x, y, w, h);
}

Castle::Castle(int x, int y, int w, int h): Sprite(x, y, w, h)
{
	Animation one = { "../../Resources/Castle1.png" };
	Animation two = { "../../Resources/Castle2.png" };
	Animation three = { "../../Resources/Castle3.png" };
	Animation four = { "../../Resources/Castle4.png" };
	anim = new Animator{one, two, three, four};
	layer = 1;
	tag = "Castle";
}

void Castle::tick() {
	if (hit) {
		tickCount++;
		
	}
	
	if (tickCount >= 30) {
		tickCount = 0;
		hit = false;
		
	}

	animate(hitCount);
}

void Castle::draw() {
	anim->draw(this);
}

void Castle::animate(int animation) {
	anim->next_image(animation);
}

void Castle::resolve_collision() {
	
	if (!hit) {
		if (hitCount >= 3) {
			gameSystem.get_current_scene()->sprites->remove(this);
		}
		else
			hitCount++;
		hit = true;
		audioHandler.castle_hit();
	}
	
}