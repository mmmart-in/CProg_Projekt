#pragma once

#include <vector>
#include "UI_Component.h"
#include <iostream>
#include <map>



class UIManager  {
	using UI_Loader = void(UIManager::*)();
public:
	static UIManager* create_instance(SDL_Renderer*);
	void change_page(std::string);
	void handle_interact(SDL_Point);
	void update_UI();
	const std::string get_active_ui_name() const;
private:
	UIManager(SDL_Renderer*);
	std::string active_ui_name;
	SDL_Renderer& renderer;
	std::map<std::string, UI_Loader> pages;
	std::vector<UI_Component*> UI_components;
	SDL_Event event;
	void create_Menu();
	void create_Gameplay();
	void create_Options();
};

