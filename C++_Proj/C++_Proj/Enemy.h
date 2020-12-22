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
    Collider* get_collider();
    void resolve_collision();
private:
    Enemy(int x, int y, int w, int h, int c, int r);
    void animate();
    void draw();
    void tick();
    void move(bool moveLeft);
   
private:
    int tickCount = 0;
    int col, row;
    float moveSpeed = 10;
    Animator* anim;
    friend class EnemyHandler;
    
};
