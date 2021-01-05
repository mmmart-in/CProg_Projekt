#pragma once
#include <SDL.h>
#include <string>
#include "UIManager.h"
#include "UI_Image.h"
class Options {
public:
	static Options* create_instance(SDL_Renderer&);
	void run();
	~Options();
private:
	Options(SDL_Renderer&);
	UIManager* UI_manager;
	std::string previous_ui_page;
	SDL_Renderer& renderer;
	SDL_Texture* background;
};

