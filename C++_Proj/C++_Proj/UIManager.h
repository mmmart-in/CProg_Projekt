#pragma once

#include <vector>
#include "UI_Page.h"
#include <iostream>
#include <map>
class UIManager  {
	using Create_Page_Function = UI_Page * (UIManager::*)();
public:
	static UIManager* create_instance(SDL_Renderer*);
	void change_page(std::string);
	void update_UI();
	inline UI_Page* get_UI() const { return active_page;  } 
private:
	UIManager(SDL_Renderer*);
	UI_Page* active_page;
	SDL_Renderer& renderer;
	std::map<std::string, Create_Page_Function> pages;

	UI_Page* create_Menu();
	UI_Page* create_Gameplay();
	UI_Page* create_Options();
};

