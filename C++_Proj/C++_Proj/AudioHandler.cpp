#include "AudioHandler.h"
#include <iostream>

AudioHandler::AudioHandler(){
	Mix_OpenAudio(20500, AUDIO_S16SYS, 2, 512);
	Mix_Music* loop = Mix_LoadMUS("E:/Downloads/post rock bounce.mp3");
	enemyShoot = Mix_LoadWAV("../../Resources/SoundFX/SpaceInvaderShoot_Kort.wav");
	playerShoot = Mix_LoadWAV("../../Resources/SoundFX/SpaceInvaders_PlayerShoot.wav");
}

void AudioHandler::enemy_shoot() {
	if(Mix_PlayChannel(-1, enemyShoot, 0) ==-1)
		std::cerr <<Mix_GetError()<< std::endl;
	std::cout << "enemyshoot kallad" << std::endl;
}
void AudioHandler::player_shoot() {
	Mix_PlayChannel(-1, playerShoot, 0);;
	std::cout << "playershoot kallad"<< std::endl;
}
void AudioHandler::castle_hit() {
	castleHit = Mix_LoadWAV("../../Resources/SoundFX/SpaceInvaders_CastleHit.wav");
	Mix_PlayChannel(-1, castleHit, 0);
}

AudioHandler audioHandler;