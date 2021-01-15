#include "Background.h"


Background* Background::get_instance(int x, int y, int w, int h){
	return new Background(x, y, w, h);
}

Background::Background(int x, int y, int w, int h) :
	Sprite(x, y, w, h)
{

	bg = new Animation{"../../Resources/back1.png",
	"../../Resources/back2.png", 
	"../../Resources/back3.png", 
	"../../Resources/back4.png", 
	"../../Resources/back5.png", 
	"../../Resources/back6.png", 
	"../../Resources/back7.png",
	"../../Resources/back8.png", 
	"../../Resources/back9.png", 
	"../../Resources/back10.png", 
	"../../Resources/back11.png",
	"../../Resources/back12.png", };
	anim = new Animator{bg};
	layer = 20;
}

Background::~Background() {
	delete anim;
}

void Background::tick() {
	tickCount++;
	if (tickCount % 5 == 0) {
		anim->next_image(0);
		tickCount = 0;
	}
}

void Background::draw() {
	anim->draw(this);
}