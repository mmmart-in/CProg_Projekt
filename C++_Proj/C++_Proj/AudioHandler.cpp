#include "AudioHandler.h"

AudioHandler::AudioHandler() {
	Mix_OpenAudio(20500, AUDIO_S16SYS, 2, 4096);
	Mix_Music* loop = Mix_LoadMUS("E:/Downloads/post rock bounce.mp3");
	Mix_PlayMusic(loop, -1);
}

void AudioHandler::PlayOnce(std::string clip) {
	//tänker att denna tar namn på clip och spelar upp detta.. frågan är hur man ska lagra dem. map? 
	Mix_Music* shot = Mix_LoadMUS("E:/Downloads/post rock bounce.mp3");
	Mix_PlayMusic(shot, 0);
}

AudioHandler audioHandler;