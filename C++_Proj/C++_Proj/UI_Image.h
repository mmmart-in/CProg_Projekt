#pragma once
#include "Component.h"
#include <string>
#include <SDL_image.h>
class UI_Image : public Component
{
public:
	static UI_Image* get_instance(SDL_Rect, std::string image);
	virtual void tick();
	virtual void draw() const;
protected:
	UI_Image(SDL_Rect, std::string image);

private:
	SDL_Texture* texture;
};

