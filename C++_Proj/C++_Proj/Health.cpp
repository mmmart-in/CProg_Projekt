#include "Health.h"
#include "GameSystem.h"

Health::Health(int h) :
	hits(0), MAXhits(h)
{
	for (int i = 0; i < h; i++) {
		UI_Image* im = new UI_Image(50 + (i * 50), 750, 25, 25, "../../Resources/ship1.png");
		lives.push_back(im);
		std::cout << " ett till liv ";
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