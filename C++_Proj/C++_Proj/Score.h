#pragma once
#include "Label.h"
#include "EventObserver.h"
#include "EnemyHandler.h"
class Score : public Label, public EventObserver
{
public:
	static Score* get_instance(int x, int y, int w, int h, int, SDL_Color, EnemyHandler&);
	void callback(EventSubject&) override;
	void tick();

private:
	Score(int x, int y, int w, int h, int, SDL_Color, EnemyHandler&);

private:
	int score, tickCount;
};

