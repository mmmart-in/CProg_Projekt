#pragma once
#include "SDL.h"
#include "Component.h"
#include <vector>
#include <string>
#include "UI_Button.h"
class UI_Page {
public:
	UI_Page(std::string);
	void add(Component*);
	const std::vector<Component*>& get_components() const;
	void interact(SDL_Point&);
	void draw_UI();
	inline std::string get_page_name() const { return page_name; }
	virtual void interact_with(Component*) = 0;
	~UI_Page();
private:
	std::string page_name;
	std::vector<Component*> components;
};

