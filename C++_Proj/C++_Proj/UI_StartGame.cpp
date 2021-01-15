#include "UI_StartGame.h"
#include "GameSystem.h"
void UI_StartGame::interact() {
	gameSystem.load_new_scene(gameSystem.get_scene_data().load_gameplay(5, 7), "Gameplay");
}

UI_StartGame::UI_StartGame(SDL_Rect rect, std::string text, SDL_Color color, std::string button_name)
	: UI_Button(rect, text, color, button_name){}

UI_StartGame* UI_StartGame::create_instance(SDL_Rect rect, std::string text, SDL_Color color, std::string button_name) {
	return new UI_StartGame(rect, text, color, button_name);
}