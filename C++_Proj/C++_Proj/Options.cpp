#include "Options.h"
#include <iostream>
#include "GameSystem.h"

Options* Options::create_instance(SDL_Renderer& renderer, std::string previous_ui_page) {
	return new Options(renderer, previous_ui_page);
}

void Options::run() {

	bool running = true;

	while (running) {
		SDL_RenderClear(&renderer);
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.type == SDL_MOUSEBUTTONDOWN && event.key.repeat == 0)
					UI_manager->handle_interact({ event.button.x, event.button.y });
			}
		}

		SDL_RenderCopy(&renderer, background, NULL, NULL);
		UI_manager->update_UI();
		SDL_RenderPresent(&renderer);
	}
}

Options::~Options() {
	UI_manager->change_page(previous_ui_page);
	delete UI_manager;
	SDL_DestroyTexture(background);
}

Options::Options(SDL_Renderer& renderer, std::string previous_ui_name) : renderer(renderer), previous_ui_page(previous_ui_name) {
	UI_manager = UIManager::create_instance(&renderer);
	UI_manager->change_page("Options");
	std::cout << previous_ui_page << std::endl;
	SDL_Surface* surface = SDL_CreateRGBSurface(0, 1200, 800, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(&renderer, NULL, SDL_PIXELFORMAT_ABGR8888, surface->pixels, surface->pitch);
	background = SDL_CreateTextureFromSurface(&renderer, surface);
	SDL_FreeSurface(surface);
	SDL_SetTextureColorMod(background, 30, 30, 30);
}




