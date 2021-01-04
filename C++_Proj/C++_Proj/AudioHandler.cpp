#include "AudioHandler.h"
#include <iostream>

AudioHandler::AudioHandler(){
	Mix_OpenAudio(20500, AUDIO_S16SYS, 2, 512);
	Mix_Music* loop = Mix_LoadMUS("E:/Downloads/post rock bounce.mp3");
	playerShoot = Mix_LoadWAV("../../Resources/SoundFX/SpaceInvaders_PlayerShoot.wav");
	enemyShoot = Mix_LoadWAV("../../Resources/SoundFX/SpaceInvaderShoot_Kort.wav");
	castleHit = Mix_LoadWAV("../../Resources/SoundFX/SpaceInvaders_CastleHit.wav");
	playerShoot->volume = 20;
	enemyShoot->volume = 20;
}

void AudioHandler::enemy_shoot() {
	
	if(Mix_PlayChannel(-1, enemyShoot, 0) ==-1)
		std::cerr <<Mix_GetError()<< std::endl;
	
}
void AudioHandler::player_shoot() {
	
	Mix_PlayChannel(-1, playerShoot, 0);;
	
}
void AudioHandler::castle_hit() {
	
	Mix_PlayChannel(-1, castleHit, 0);
}

AudioHandler audioHandler;