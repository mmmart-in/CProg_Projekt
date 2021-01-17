#ifndef UI_START_GAME_H
#define UI_START_GAME_H

#include "UI_Button.h"
class UI_StartGame : public UI_Button {
public:
	static UI_StartGame* create_instance(SDL_Rect, std::string, SDL_Color, std::string);
	void interact() override;
private:
	UI_StartGame(SDL_Rect, std::string, SDL_Color, std::string);
};

#endif