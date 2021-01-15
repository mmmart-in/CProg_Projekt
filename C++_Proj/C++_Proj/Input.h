#pragma once
#include <SDL.h>
#include <map>
#include <string>

class Input {
public:
	Input();
	void add_keybind(std::string, SDL_Scancode);
	void rebind_key();
	bool get_key_down(std::string);
	bool get_key(SDL_Scancode);
	~Input();
private:
	const Uint8* keyboard;
	std::map<std::string, SDL_Scancode> keybinds;
};

extern Input input;



