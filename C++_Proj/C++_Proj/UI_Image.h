#pragma once
#include "UI_Component.h"
#include <string>
#include <SDL_image.h>

class UI_Image : public UI_Component
{
public:
	static UI_Image* get_instance(SDL_Rect, std::string image);
	void tick() override;
	void draw() override;
	void interact() override {}
	~UI_Image();
protected:
	UI_Image(SDL_Rect, std::string image);

private:
	SDL_Texture* texture;
};

