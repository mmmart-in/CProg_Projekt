#pragma once
#include "MovableSprite.h"
#include <string>
#include "Animator.h"
class Bullet :
    public MovableSprite
{
public:
    ~Bullet();
    virtual void move();
    void draw();
    void tick();
    void animate();
    void resolve_collision();
    
protected:
    int tickCount;
    float movementSpeed = 5;
    Animator* anim;
    Bullet(int x, int y, int w, int h);
    
  
    
};

