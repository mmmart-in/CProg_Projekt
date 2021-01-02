#pragma once
#include "FixedSprite.h"
#include "Animation.h"
#include "Animator.h"
class Castle :
    public FixedSprite
{
public:
    static Castle* get_instance(int x, int y, int w, int h);
    

    void draw();
    void tick();
    void resolve_collision();
private:
    Castle(int x, int y, int w, int h);
    void animate(int);
private:
    Animator* anim;
    int hitCount, tickCount;
    bool hit;
    
};

