#pragma once
#include "MovableSprite.h"
#include <string>
#include "Animator.h"

class Enemy :
    public MovableSprite
{
public:
    static Enemy* get_instance(int x, int y, int w, int h, int c, int r);
    ~Enemy();
private:
    void move_right(); 
    void move_left();
    Enemy(int x, int y, int w, int h, int c, int r);
    void animate();
    void draw();
    void tick();
    Animator* anim;
    int tickCount = 0;
    int col, row;

    friend class EnemyHandler;
    
};
