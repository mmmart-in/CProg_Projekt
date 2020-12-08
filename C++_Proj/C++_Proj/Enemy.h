#pragma once
#include "MovableSprite.h"
#include <string>
class Enemy :
    public MovableSprite
{
public:
    Enemy(int x, int y, int w, int h, std::string image);
    ~Enemy();
private:
    void tick();

    
};


static int enemyCount;