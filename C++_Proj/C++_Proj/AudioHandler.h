#pragma once
#include <SDL_mixer.h>
#include <string>

class AudioHandler
{
public:
	
	AudioHandler();
	void PlayOnce(std::string);
private:
	Mix_Chunk* loop;
};

extern AudioHandler audioHandler;

