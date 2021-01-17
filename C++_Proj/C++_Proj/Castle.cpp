#include "Castle.h"
#include "GameSystem.h"
#include <iostream>
#include "AudioHandler.h"
Castle* Castle::get_instance(int x, int y, int w, int h) {
	return new Castle(x, y, w, h);
}

Castle::Castle(int x, int y, int w, int h): Sprite(x, y, w, h), hit(false), hitCount(0), tickCount(0)
{
	one = new Animation{ "../../Resources/Castle1.png" };
	two = new Animation{ "../../Resources/Castle2.png" };
	three = new Animation{ "../../Resources/Castle3.png" };
	four = new Animation{ "../../Resources/Castle4.png" };
	anim = new Animator{one, two, three, four};
	set_layer(1);
	set_tag("Castle");
}

Castle::~Castle() {
	delete one;
	delete two;
	delete three;
	delete four;
	delete anim;
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
			gameSystem.get_current_scene().sprites->remove(this);
		}
		else
			hitCount++;
		hit = true;
		gameSystem.get_audio_handler().castle_hit();
	}
	
}