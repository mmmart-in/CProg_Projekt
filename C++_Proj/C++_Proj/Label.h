#pragma once

#include "Component.h"
#include <string>
class Label : public Component{
public:
	static Label* getInstance(int, int, int, int, std::string, SDL_Color);
	std::string getText() const;
	void draw() const;
	void tick();
	void setText(std::string newText);
	~Label();
protected:
	Label(int x, int y, int w, int h, std::string txt, SDL_Color);
private:
	std::string text;
	SDL_Texture* texture;
	SDL_Color textColor;
};
