#pragma once
#include "Sprite.h"
#include <string>
class FixedSprite :
    public Sprite
{
protected:
    FixedSprite(int, int, int, int);
    ~FixedSprite();
    virtual Collider* get_collider() = 0;
    virtual void resolve_collision() = 0;
private:
    virtual void tick() = 0;
    virtual void draw() = 0;
    
};

