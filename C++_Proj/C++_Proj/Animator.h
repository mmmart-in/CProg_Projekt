#pragma once
#include <vector>
#include <SDL.h>
#include <initializer_list>
#include <string>
#include "Animation.h"

class Animator
{

public:
	Animator(std::initializer_list<Animation>);
private:
	std::vector<Animation> texts;

};

