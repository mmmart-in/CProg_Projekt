#include "UI_Menu.h"
#include <iostream>
#include "GameSystem.h"
#include "SceneData.h"
#include "Button_StartGame.h"

void UI_Menu::interact_with(UI_Button* button) {
	if (button)
		button->invoke();
}
