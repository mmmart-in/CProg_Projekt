#pragma once
#include "MovableSprite.h"
#include <string>
#include "Animator.h"
#include "EventSubject.h"

class Enemy :
    public MovableSprite, public EventSubject
{
public:
    static Enemy* get_instance(int x, int y, int w, int h, int c, int r);
    ~Enemy();
    void Shoot();
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
    float moveSpeed = 15;
    Animator* anim;
    friend class EnemyHandler;
    
};
