#pragma once
#include "MovableSprite.h"
#include <string>
#include "Animator.h"

class Enemy :
    public MovableSprite
{
public:
    static Enemy* get_instance(int x, int y, int w, int h);
    ~Enemy();
private:
    void animate();
    void draw();
    void tick();
    Enemy(int x, int y, int w, int h);
    Animator* anim;
    int tickCount = 0;

    friend class EnemyHandler;
    
};


static int enemyCount;