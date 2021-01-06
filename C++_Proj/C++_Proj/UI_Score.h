#pragma once
#include "UI_Label.h"
#include "EventObserver.h"
#include "EnemyHandler.h"

class UI_Score : public UI_Label, public EventObserver
{
public:
	static UI_Score* get_instance(int x, int y, int w, int h, int, SDL_Color, EnemyHandler&);
	void callback(EventSubject&) override;
	void tick();
private:
	UI_Score(int x, int y, int w, int h, int, SDL_Color, EnemyHandler&);

private:
	int score, tickCount;
};

