#ifndef UI_LABEL_H
#define UI_LABEL_H

#include "UI_Component.h"
#include <string>

class UI_Label : public UI_Component{
public:
	static UI_Label* getInstance(SDL_Rect, std::string, SDL_Color);
	std::string getText() const;
	void draw() override;
	void tick() override {}
	void interact() override {}
	void setText(std::string newText);
	const SDL_Texture* get_texture() const;
	~UI_Label();
protected:
	UI_Label(SDL_Rect, std::string txt, SDL_Color);
private:
	std::string text;
	SDL_Texture* texture;
	SDL_Color textColor;
};

#endif