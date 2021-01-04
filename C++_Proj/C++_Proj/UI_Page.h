#pragma once
#include "SDL.h"
#include "Component.h"
#include <vector>
#include <string>
#include "UI_Button.h"
class UI_Page {
public:
	void add(Component*);
	const std::vector<Component*>& get_components() const;
	void interact(SDL_Point&);
	void draw_UI();
	virtual void interact_with(UI_Button*) = 0;
	~UI_Page();
private:
	std::vector<Component*> components;
};

