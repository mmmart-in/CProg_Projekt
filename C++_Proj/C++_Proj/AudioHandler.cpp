#include "AudioHandler.h"

AudioHandler::AudioHandler() {
	Mix_OpenAudio(20500, AUDIO_S16SYS, 2, 4096);
	Mix_Music* loop = Mix_LoadMUS("E:/Downloads/post rock bounce.mp3");
	Mix_PlayMusic(loop, -1);
}

void AudioHandler::PlayOnce(std::string clip) {
	//t�nker att denna tar namn p� clip och spelar upp detta.. fr�gan �r hur man ska lagra dem. map? 
	Mix_Music* shot = Mix_LoadMUS("E:/Downloads/post rock bounce.mp3");
	Mix_PlayMusic(shot, 0);
}

AudioHandler audioHandler;