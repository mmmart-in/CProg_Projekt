#ifndef BULLET_H
#define BULLET_H

#include <string>
#include "Animator.h"
#include "Animation.h"
class Bullet : public Sprite
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
    float movementSpeed = 7;
    Animator* anim;
    Animation* animation;
    Bullet(int x, int y, int w, int h);
    
  
    
};


#endif
