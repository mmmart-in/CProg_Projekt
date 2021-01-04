#pragma once

#include <vector>
#include "UI_Page.h"
#include <iostream>
class UIManager  {
public:
	static UIManager* create_instance(SDL_Renderer*);
	void change_page(std::string);
	inline UI_Page* get_UI() const { return active_page;  } 
private:
	UIManager(SDL_Renderer*);
	UI_Page* active_page;
	SDL_Renderer& renderer;
	std::vector<UI_Page*> pages;
};

