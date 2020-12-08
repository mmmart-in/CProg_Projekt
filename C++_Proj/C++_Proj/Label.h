#pragma once

#include "Component.h"
#include <string>
class Label : public Component{
public:
	static Label* getInstance(int x, int y, int w, int h, std::string txt);
	std::string getText() const;
	void draw() const;
	void setText(std::string newText);
	~Label();
protected:
	Label(int x, int y, int w, int h, std::string txt);
private:
	std::string text;
	SDL_Texture* texture;
};
