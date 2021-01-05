#include "Button_Options.h"
#include "GameSystem.h"
Button_Options::Button_Options(SDL_Rect rect, std::string text, SDL_Color color, std::string name) 
: UI_Button(rect, text, color, name) {}

void Button_Options::invoke() {
	gameSystem.get_ui_manager()->change_page("Options");
}
