#pragma once
#include "Animation.h"
#include "Animator.h"
class Castle : public Sprite
{
public:
    static Castle* get_instance(int x, int y, int w, int h);
    ~Castle();
    void draw();
    void tick();
    void resolve_collision();
private:
    Castle(int x, int y, int w, int h);
    void animate(int);
private:
    Animator* anim;
    Animation* one, * two, * three, * four;
    int hitCount, tickCount;
    bool hit;
};

