#pragma once
#include "MovableSprite.h"
#include <string>
#include "Animator.h"
class Bullet :
    public MovableSprite
{
public:
    static Bullet* get_instance(int x, int y, int w, int h, std::string image);
    ~Bullet();
    void draw();
    void tick();
    void fly();
private:
    
    Bullet(int x, int y, int w, int h, std::string image);
    Animator* anim;
    int tickCount;
};

