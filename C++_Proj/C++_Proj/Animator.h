#pragma once
#include <vector>
#include <SDL.h>
#include <initializer_list>
#include <string>
#include "Animation.h"
#include "Sprite.h"

class Animator
{

public:
	Animator(std::initializer_list<Animation>);
	void draw(Sprite*);
	void next_image(int);
	void animate_loop(int);
private:
	std::vector<Animation> animations;
	SDL_Texture* activeTexture;
	int activeInt;

};

