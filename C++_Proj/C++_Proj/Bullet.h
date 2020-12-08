#pragma once
#include "MovableSprite.h"
#include <string>
class Bullet :
    public MovableSprite
{
public:
    Bullet(int x, int y, int w, int h, std::string image);
    ~Bullet();
private:
    void tick();
};

