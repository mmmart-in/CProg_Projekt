#include "Score.h"



Score* Score::get_instance(int x, int y, int w, int h, int s, SDL_Color col, EnemyHandler& eh)
{
	return new Score(x, y, w, h, s, col, eh);
}


Score::Score(int x, int y, int w, int h, int s, SDL_Color col, EnemyHandler& eh) :
	Label({ x, y, w, h }, std::to_string(s), col), score(s), tickCount(0) {

	for (Enemy* e : eh.get_enemies()) {
		e->attach(*this);
	}
}
 
void Score::callback(EventSubject& subject) {
	score += 100;
}

void Score::tick() {
	tickCount++;
	if (tickCount % 10 == 0) {
		score++;
	}
	setText(std::to_string(score));
}