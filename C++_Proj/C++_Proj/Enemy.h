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
    static Enemy* get_instance(int x, int y, int w, int h);
    ~Enemy();

private:
    Enemy(int x, int y, int w, int h);
    void tick();
    Animator* anim;
    int tickCount = 0;
    
};


static int enemyCount;