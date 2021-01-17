#include "UI_Exit.h"
#include "GameSystem.h"

void UI_Exit::interact() {
	gameSystem.get_ui_manager()->change_page("Menu");
}

UI_Exit::UI_Exit(SDL_Rect rect, std::string text, SDL_Color color, std::string button_name)
	: UI_Button(rect, text, color, button_name) {}

UI_Exit* UI_Exit::create_instance(SDL_Rect rect, std::string text, SDL_Color color, std::string button_name) {
	return new UI_Exit(rect, text, color, button_name);
}