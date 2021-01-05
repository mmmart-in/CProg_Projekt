#pragma once

#include "Component.h"
#include <string>
class Label : public Component{
public:
	static Label* getInstance(SDL_Rect, std::string, SDL_Color);
	std::string getText() const;
	void draw() const;
	void tick();
	void setText(std::string newText);
	const SDL_Texture* get_texture() const;
	~Label();
protected:
	Label(SDL_Rect, std::string txt, SDL_Color);
private:
	std::string text;
	SDL_Texture* texture;
	SDL_Color textColor;
};
