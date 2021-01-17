#include "UI_HowToPlay.h"
#include "GameSystem.h"
void UI_HowToPlay::interact() {
	gameSystem.get_ui_manager()->change_page("HowToPlay");
}

UI_HowToPlay::UI_HowToPlay(SDL_Rect rect, std::string text, SDL_Color color, std::string button_name)
	: UI_Button(rect, text, color, button_name) {}

UI_HowToPlay* UI_HowToPlay::create_instance(SDL_Rect rect, std::string text, SDL_Color color, std::string button_name) {
	return new UI_HowToPlay(rect, text, color, button_name);
}