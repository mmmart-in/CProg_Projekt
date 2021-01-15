#include "UI_Textfield.h"
#include <iostream>
#include "GameSystem.h"

void UI_Textfield::run() {

	has_focus = true;

	std::cout << "starting text" << std::endl;
	SDL_StartTextInput();
	while (has_focus) {
		SDL_RenderClear(&gameSystem.get_renderer());
		bool render_text = false;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_TEXTINPUT:
				text += event.text.text;
				render_text = true;
				break;
			case SDL_KEYDOWN:
				SDL_Scancode keyDown = event.key.keysym.scancode;
				switch (keyDown) {
				case SDL_SCANCODE_BACKSPACE:
					if (text.length() > 0) {
						text.pop_back();
						render_text = true;
					}
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
		if (render_text) {
			draw();
			SDL_RenderPresent(&gameSystem.get_renderer());
		}
			
	}

	SDL_StopTextInput();
}

void UI_Textfield::draw()  {
	write_rect.w = text_size * text.length();
	SDL_DestroyTexture(texture);
	SDL_Surface* surf = TTF_RenderText_Solid(gameSystem.get_current_window().get_font(), text.c_str(), { 255, 255, 255 });
	texture = SDL_CreateTextureFromSurface(&gameSystem.get_renderer(), surf);
	SDL_FreeSurface(surf);
	SDL_RenderCopy(&gameSystem.get_renderer(), texture, NULL, &write_rect);
}

void UI_Textfield::interact() {
	std::cout << "textfield" << std::endl;
	run();
}

UI_Textfield::UI_Textfield(SDL_Rect rect, SDL_Color color, std::string init_text) : UI_Component(rect), text(init_text) {
	SDL_Surface* surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 0));
	write_rect = { rect.x, rect.y, text_size, text_size };
	SDL_Surface* surf = TTF_RenderText_Solid(gameSystem.get_current_window().get_font(), text.c_str(), color);
	texture = SDL_CreateTextureFromSurface(&gameSystem.get_renderer(), surf);
	SDL_FreeSurface(surf);
}

UI_Textfield* UI_Textfield::create_instance(SDL_Rect rect, SDL_Color color, std::string init_text) {
	return new UI_Textfield(rect, color, init_text);
}
