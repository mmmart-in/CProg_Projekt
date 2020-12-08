#include "MainWindow.h"
#include <SDL.h>


MainWindow::MainWindow() 
{
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, 0);
	ren = SDL_CreateRenderer(win, -1, 0);
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	SDL_RenderPresent(ren);
}

MainWindow::~MainWindow() 
{
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
}

SDL_Renderer* MainWindow::get_ren() const 
{
	return ren;
}

MainWindow mainWindow;