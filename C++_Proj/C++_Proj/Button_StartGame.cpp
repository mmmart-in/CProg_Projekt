#include "Button_StartGame.h"
#include "GameSystem.h"
#include "SceneData.h"
#include "GameSystem.h"

Button_StartGame::Button_StartGame(SDL_Rect rect, std::string button_text, SDL_Color color, std::string button_name, int rows, int columns) :
	UI_Button(rect, button_text, color, button_name), rows(rows), columns(columns) {}


Button_StartGame* Button_StartGame::create_instance(SDL_Rect rect, std::string button_text, SDL_Color color, std::string button_name, int rows, int columns) {

	return new Button_StartGame(rect, button_text, color, button_name, rows, columns);
}

void Button_StartGame::invoke() {
	gameSystem.load_new_scene(gameSystem.get_scene_data()->load_gameplay(rows, columns), "Gameplay");
}
