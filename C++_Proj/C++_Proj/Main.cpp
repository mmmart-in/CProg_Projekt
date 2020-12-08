#include <iostream>
#include <SDL.h>
#include "MainWindow.h"
#include "GameSystem.h"

int main(int argc, char** argv) {
	GameSystem gameSystem;

	gameSystem.run();
	return 0;
}