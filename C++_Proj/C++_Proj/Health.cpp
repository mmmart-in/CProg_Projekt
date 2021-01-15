#include "Health.h"
#include "GameSystem.h"


Health* Health::get_instance(int h) {
	return new Health(h);
}

Health::Health(int h) :
	hits(0), MAXhits(h)
{
	for (int i = 0; i < h; i++) {
		UI_Image* im = UI_Image::get_instance({ 50 + (i * 50), 750, 25, 25 }, "../../Resources/ship1.png");
		lives.push_back(im);
	}
}

void Health::get_hit() {
	lives.erase(lives.end() - 1);
	hits++;
}


void Health::draw() {
	for (UI_Image* ui : lives) {
		ui->draw();
	}
}

void Health::tick() {
	if (hits >= MAXhits)
		gameSystem.game_over(true);
}

Health::~Health() {
	for (auto& x : lives)
		delete x;
}