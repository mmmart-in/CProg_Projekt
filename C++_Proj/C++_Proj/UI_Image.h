#pragma once
#include "Component.h"
#include <string>
#include <SDL_image.h>
class UI_Image : public Component
{
public:
	UI_Image(int x, int y, int w, int h, std::string image);
	void tick();
	void draw() const;
private:
	SDL_Texture* texture;
};

