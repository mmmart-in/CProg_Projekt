#pragma once
#include "Component.h"
#include <string>
#include <SDL_image.h>
class UI_Image : public Component
{
public:
	static UI_Image* get_instance(int x, int y, int w, int h, std::string image);
	virtual void tick();
	virtual void draw() const;
protected:
	UI_Image(int x, int y, int w, int h, std::string image);

private:
	
	SDL_Texture* texture;
};

