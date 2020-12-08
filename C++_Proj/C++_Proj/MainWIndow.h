#pragma once
#include <SDL.h>



class MainWindow
{
public:
	MainWindow();
	~MainWindow();
	SDL_Renderer* get_ren() const;

private: 
	SDL_Window* win;
	SDL_Renderer* ren;

};


//fungerar detta utan namespace? vill vi göra såhär? vem vet? 
	extern MainWindow mainWindow;

