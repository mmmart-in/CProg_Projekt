#pragma once
#include "MovableSprite.h"
class Enemy :
    public MovableSprite
{
public:
    Enemy(int x, int y, int w, int h);
    ~Enemy();
private:
    void tick();

    
};


static int enemyCount;