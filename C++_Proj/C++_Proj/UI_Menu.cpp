#include "UI_Menu.h"
#include <iostream>
#include "GameSystem.h"
#include "SceneData.h"
#include "Button_StartGame.h"

UI_Menu::UI_Menu(std::string page_name) : UI_Page(page_name) {}

void UI_Menu::interact_with(Component* component) {
	
	UI_Button* button = dynamic_cast<UI_Button*>(component);
	if (button) {
		button->invoke();
	}
}