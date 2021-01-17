#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <SDL_image.h>
#include <initializer_list>
#include <string>
#include "MainWindow.h"

class Animation
{
public:
	Animation(std::initializer_list<std::string>);
	~Animation();
	SDL_Texture* get_texture_at(int);
	int get_size();
private:
	std::vector<SDL_Texture*> texts;
};

#endif