#ifndef UI_HOW_TO_PLAY_H
#define UI_HOW_TO_PLAY_H

#include "UI_Button.h"
class UI_HowToPlay : public UI_Button {
public:
	static UI_HowToPlay* create_instance(SDL_Rect, std::string, SDL_Color, std::string);
	void interact() override;
private:
	UI_HowToPlay(SDL_Rect, std::string, SDL_Color, std::string);
};

#endif