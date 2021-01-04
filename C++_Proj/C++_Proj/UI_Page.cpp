#include "UI_Page.h"
#include <iostream>
#include "UI_Button.h"
UI_Page* UI_Page::create_instance(std::string page_name) {
	return new UI_Page(page_name);
}

void UI_Page::add(Component* component) {
	components.push_back(component);
	std::cout << "Pushed int" << std::endl;
}

const std::string& UI_Page::get_page_name(std::string name) const {
	return page_name;
}

const std::vector<Component*>& UI_Page::get_components() const {
	return components;
}

void UI_Page::interact(SDL_Point& clicked_point) {
	for (auto& component : components)
		if (SDL_PointInRect(&clicked_point, &component->get_rect())) {
			UI_Button* button = dynamic_cast<UI_Button*>(component);
			if (button) 
				button->notify();
		}   
}

UI_Page::UI_Page(std::string page_name) : page_name(page_name) {}
