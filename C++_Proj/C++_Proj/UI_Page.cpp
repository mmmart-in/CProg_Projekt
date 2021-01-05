#include "UI_Page.h"
#include <iostream>
#include "UI_Button.h"
#include "GameSystem.h"
UI_Page::UI_Page(std::string page_name) : page_name(page_name) {}

void UI_Page::add(Component* component) {
	components.push_back(component);
}

const std::vector<Component*>& UI_Page::get_components() const {
	return components;
}

void UI_Page::interact(SDL_Point& clicked_point) {
	for (auto& component : components)
		if (SDL_PointInRect(&clicked_point, &component->get_rect()))
			interact_with(dynamic_cast<UI_Button*>(component));
}

void UI_Page::draw_UI() {
	for (auto& comp : components)
		comp->draw();
}

UI_Page::~UI_Page() {
	for (auto it = components.begin(); it != components.end(); it++)
		delete* it;
}

