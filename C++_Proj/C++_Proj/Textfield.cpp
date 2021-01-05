#include "Textfield.h"
#include <iostream>
#include "GameSystem.h"

void Textfield::run() {

	has_focus = true;
	bool render_text = false;
	std::cout << "starting text" << std::endl;
	SDL_StartTextInput();
	while (has_focus) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_TEXTINPUT:
				text += event.text.text;
				render_text = true;
				std::cout << text << std::endl;
				break;
			case SDL_KEYDOWN:
				SDL_Scancode keyDown = event.key.keysym.scancode;
				switch (keyDown) {
				case SDL_SCANCODE_BACKSPACE:
					if (text.length() > 0)
						text.pop_back();
					std::cout << text << std::endl;
					break;
				case SDL_SCANCODE_ESCAPE:
					has_focus = false;
					break;
				case SDL_SCANCODE_SPACE:
					text += " ";
					render_text = true;
					break;
				}
			}
		}
		if (render_text)
			draw();

	}

	SDL_StopTextInput();
}

void Textfield::draw() const {
	SDL_RenderCopy(&gameSystem.get_renderer(), NULL, NULL, &get_rect());
	SDL_RenderDrawRect(&gameSystem.get_renderer(), &get_rect());
	SDL_SetRenderDrawColor(&gameSystem.get_renderer(), 255, 255, 255, 255);
}

Textfield::Textfield(SDL_Rect rect, SDL_Color color) : Component(rect) {
	SDL_Surface* surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 0, 0));
}

Textfield* Textfield::create_instance(SDL_Rect rect, SDL_Color color) {
	return new Textfield(rect, color);
}
