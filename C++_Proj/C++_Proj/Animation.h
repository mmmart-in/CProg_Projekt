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
	SDL_Texture* get_texture_at(int) const;
	const int get_size() const;
private:
	std::vector<SDL_Texture*> texts;
};

#endif