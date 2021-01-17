#pragma once
#include <SDL_mixer.h>
#include <string>

class AudioHandler
{
public:
	
	AudioHandler();
	~AudioHandler();
	void enemy_shoot();
	void castle_hit();
	void player_shoot();
private:
	Mix_Chunk* loop;
	Mix_Chunk* castleHit;
	Mix_Chunk* enemyShoot;
	Mix_Chunk* playerShoot;
};


