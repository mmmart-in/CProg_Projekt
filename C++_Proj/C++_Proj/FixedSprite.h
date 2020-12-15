#pragma once
#include "Sprite.h"
#include <string>
class FixedSprite :
    public Sprite
{
protected:
    FixedSprite(int, int, int, int);
    ~FixedSprite();
private:
    virtual void tick() = 0;
    virtual void draw() = 0;
    
};

