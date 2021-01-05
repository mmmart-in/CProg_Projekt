#pragma once
#include "SDL.h"
#include <string>
#include "UI_Button.h"

class Button_StartGame : public UI_Button {
public:
	Button_StartGame(SDL_Rect, std::string, SDL_Color, std::string, int, int);
	void invoke() override;
private:
	int rows, columns;

};

