#include "Input.h"
#include <iostream>
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

void Input::rebind_key() {
	std::cout << "Keybinds: " << std::endl;
	for (auto keybind : keybinds)
		std::cout << "Action: '" << keybind.first << "'" << " - Key: " << SDL_GetScancodeName(keybind.second) << std::endl;
	
	std::string command;
	std::cin >> command;
	
	auto it = keybinds.find(command);
	
	if(it != keybinds.end()) {
		SDL_Scancode newKey = SDL_SCANCODE_UNKNOWN;
		bool correct_input = false;
		do {
			std::cout << "Enter new keybind: ";
			std::string input;
			std::cin >> input;

			SDL_Scancode newKey = SDL_GetScancodeFromName(input.c_str());

			if (newKey != SDL_SCANCODE_UNKNOWN) {
				it->second = newKey;
				correct_input = true;
			}
			else
				std::cout << "Couldn't find key, enter correct format (ex ""Space"" for space)" << std::endl;

		} while (!correct_input);
	}
}

Input::~Input() {
	delete keyboard;
}


Input input;
