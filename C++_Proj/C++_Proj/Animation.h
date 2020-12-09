#pragma once
#include <vector>
#include <SDL_image.h>
#include <initializer_list>
#include <string>
#include "MainWindow.h"

class Animation
{
public:
	Animation(std::initializer_list<std::string>);
	SDL_Texture* get_texture_at(int);
private:
	std::vector<SDL_Texture*> texts;
};

