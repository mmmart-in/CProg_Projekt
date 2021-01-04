#pragma once
#include "SDL.h"
#include "Component.h"
#include <vector>
#include <string>

class UI_Page {
public:
	static UI_Page* create_instance(std::string);
	void add(Component*);
	const std::string& get_page_name(std::string) const;
	const std::vector<Component*>& get_components() const;
	void interact(SDL_Point&);
private:
	UI_Page(std::string);
	std::string page_name;
	std::vector<Component*> components;
};

