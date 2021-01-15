#pragma once
#include "Bullet.h"
#include "GameSystem.h"
class EnemyBullet : public Bullet
{
public:
	static EnemyBullet* get_instance(int x, int y, int w, int h);
    void move();
    void tick();

private:
	EnemyBullet(int x, int y, int w, int h);
};

