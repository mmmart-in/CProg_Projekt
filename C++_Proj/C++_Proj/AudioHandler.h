#pragma once
#include <SDL_mixer.h>
#include <string>

class AudioHandler
{
public:
	
	AudioHandler();
	~AudioHandler();
	void enemy_shoot() const;
	void castle_hit() const;
	void player_shoot() const;
private:
	Mix_Chunk* loop;
	Mix_Chunk* castleHit;
	Mix_Chunk* enemyShoot;
	Mix_Chunk* playerShoot;
};

extern AudioHandler audioHandler;

