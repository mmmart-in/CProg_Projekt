#ifndef OPTIONS_H
#define OPTIONS_H

#include <SDL.h>
#include <string>
#include "UIManager.h"
#include "UI_Image.h"
class Options {
public:
	static Options* create_instance(SDL_Renderer&, std::string);
	void run();
	~Options();
private:
	Options(SDL_Renderer&, std::string);
	UIManager* UI_manager;
	std::string previous_ui_page;
	SDL_Renderer& renderer;
	SDL_Texture* background;
};

#endif