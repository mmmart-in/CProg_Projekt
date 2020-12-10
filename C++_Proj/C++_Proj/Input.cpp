#include "Input.h"

Input::Input() {
	keyboard = SDL_GetKeyboardState(NULL);
}

void Input::add_keybind(std::string command, SDL_Scancode key) {
	keybinds.insert(std::pair<std::string, SDL_Scancode>(command, key));
}

bool Input::get_key_down(std::string command) {
	auto it = keybinds.find(command);
	return it != keybinds.end() ? keyboard[it->second] : false; 
}

bool Input::get_key(SDL_Scancode key) {
	return keyboard[key];
}

Input input;
