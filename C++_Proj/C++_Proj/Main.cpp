#include <iostream>
#include <SDL.h>
#include "MainWindow.h"
#include "GameSystem.h"
#include "Label.h"

int main(int argc, char** argv) {
	GameSystem gameSystem;

	Label* lb = Label::getInstance(200, 200, 200, 200, "HALLÅ");
	gameSystem.add_component(lb);
	gameSystem.run();
	return 0;
}