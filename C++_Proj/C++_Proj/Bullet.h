#pragma once
#include "MovableSprite.h"
class Bullet :
    public MovableSprite
{
public:
    Bullet(int x, int y, int w, int h);
    void tick();
};

