#pragma once
#include "MovableSprite.h"
class Enemy :
    public MovableSprite
{
public:
    Enemy(int x, int y, int w, int h);
    ~Enemy();
    void tick();
private:
    static int enemyCount;
};

