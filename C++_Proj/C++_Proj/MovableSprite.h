#pragma once
#include "Sprite.h"
class MovableSprite :
    public Sprite
{
public:

protected:
    MovableSprite(int x, int y, int w, int h, std::string image);
    virtual void tick() = 0;
    
};

