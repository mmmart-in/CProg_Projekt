#ifndef UI_IMAGE_H
#define UI_IMAGE_H

#include "UI_Component.h"
#include <string>
#include <SDL_image.h>

class UI_Image : public UI_Component
{
public:
	static UI_Image* get_instance(SDL_Rect, std::string image);
	static UI_Image* get_instance(SDL_Rect, SDL_Texture*);
	void tick() override;
	void draw() override;
	void interact() override {}
	~UI_Image();
protected:
	UI_Image(SDL_Rect, std::string image);
	UI_Image(SDL_Rect, SDL_Texture*);

private:
	SDL_Texture* texture;
};

#endif