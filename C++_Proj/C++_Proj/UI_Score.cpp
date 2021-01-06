#include "UI_Score.h"



UI_Score* UI_Score::get_instance(int x, int y, int w, int h, int s, SDL_Color col, EnemyHandler& eh)
{
	return new UI_Score(x, y, w, h, s, col, eh);
}


UI_Score::UI_Score(int x, int y, int w, int h, int s, SDL_Color col, EnemyHandler& eh) :
	UI_Label({ x, y, w, h }, std::to_string(s), col), score(s), tickCount(0) {

	for (Enemy* e : eh.get_enemies()) {
		e->attach(*this);
	}
}
 
void UI_Score::callback(EventSubject& subject) {
	score += 100;
}

void UI_Score::tick() {
	tickCount++;
	if (tickCount % 10 == 0) {
		score++;
	}
	setText(std::to_string(score));
}