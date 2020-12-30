#pragma once
#include "Sprite.h"
class MovableSprite :
    public Sprite
{
public:

protected:
    MovableSprite(int x, int y, int w, int h);
    virtual void tick() = 0;
    virtual void draw() = 0;
    virtual void resolve_collision() = 0;
    
};

