#pragma once
#include "MovableSprite.h"
#include <string>
#include "Animator.h"

class Enemy :
    public MovableSprite
{
public:
    void draw();
    void animate();
    Enemy(int x, int y, int w, int h, std::string image);
    ~Enemy();
private:
    void tick();
    Animator* anim;
    int tickCount;
    
};


static int enemyCount;