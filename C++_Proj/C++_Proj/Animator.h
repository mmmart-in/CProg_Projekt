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
	//TEMPOR�RT: DENNA �R SPECIFIK F�R PLAYER...
	void change_image(int);
	void animate_loop(int);
private:
	std::vector<Animation> animations;
	SDL_Texture* activeTexture;

};

