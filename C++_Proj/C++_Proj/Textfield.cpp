#include "Textfield.h"
#include <iostream>
#include "GameSystem.h"

void Textfield::tick() {
	has_focus = true;
	bool render_text = false;
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
}

Textfield::Textfield(SDL_Rect rect) : Component(rect) {}

Textfield* Textfield::create_instance(SDL_Rect rect) {
	return new Textfield(rect);
}
