#pragma once
#include "Sprite.h"
#include <string>
class FixedSprite :
    public Sprite
{
protected:
    FixedSprite(int, int, int, int, std::string image);
    ~FixedSprite();
private:
    virtual void draw() = 0;
    
};

