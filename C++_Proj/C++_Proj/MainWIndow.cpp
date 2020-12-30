#include "MainWindow.h"
#include <SDL.h>
#include <iostream>
#include "AudioHandler.h"

MainWindow::MainWindow() 
{
	SDL_Init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, 0);
	ren = SDL_CreateRenderer(win, -1, 0);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	SDL_RenderPresent(ren);
	TTF_Init();
	font = TTF_OpenFont("../../Resources/Minecraft.ttf", 36);
	std::cout << TTF_GetError();

}

MainWindow::~MainWindow() 
{
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
	TTF_CloseFont(font);
	TTF_Quit();
}

SDL_Renderer* MainWindow::get_ren() const 
{
	return ren;
}

TTF_Font* MainWindow::get_font() const 
{
	return font;
}

/*int* MainWindow::get_width() {
	int* widthPoint = nullptr; 
	SDL_GetWindowSize(win, widthPoint, NULL);
		return widthPoint;
}*/

MainWindow mainWindow;