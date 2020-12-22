#pragma once
#include "MovableSprite.h"
#include <string>
#include "Animator.h"
class Bullet :
    public MovableSprite
{
public:
    static Bullet* get_instance(int x, int y, int w, int h);
    ~Bullet();
    void move();
    void draw();
    void tick();
    void animate();
    void resolve_collision();
    Collider* get_collider();
    
    

private:
    int tickCount;
    float movementSpeed = 3;
    Animator* anim;
    Bullet(int x, int y, int w, int h);
    
  
    
};

