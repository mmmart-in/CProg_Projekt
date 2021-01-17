#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>


class MainWindow
{
public:
	MainWindow();
	~MainWindow();
	SDL_Renderer* get_ren() const;
	TTF_Font* get_font() const;

private: 
	SDL_Window* win;
	SDL_Renderer* ren;
	TTF_Font* font;
};

