#pragma once
#include "Sprite.h"
class FixedSprite :
    public Sprite
{
protected:
    FixedSprite(int, int, int, int);
    ~FixedSprite();
private:
    virtual void draw() = 0;
    
};

