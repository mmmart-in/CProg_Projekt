#pragma once
#include "Sprite.h"
class MovableSprite :
    public Sprite
{

protected:
    MovableSprite(int x, int y, int w, int h);
    virtual void tick() = 0;
    int speed;
};

