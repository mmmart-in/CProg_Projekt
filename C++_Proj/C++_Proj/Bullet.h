#pragma once
#include "MovableSprite.h"
#include <string>
class Bullet :
    public MovableSprite
{
public:
    static Bullet* get_instance(int x, int y, int w, int h, std::string image);
    ~Bullet();
    void draw();
    void tick();
private:
    
    Bullet(int x, int y, int w, int h, std::string image);
};

