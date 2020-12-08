#pragma once
#include "MovableSprite.h"
class Player :
    public MovableSprite
{
public:
    Player(int x, int y, int w, int h);
    void tick();
    void move();
    void shoot();
    void check_collision(); //??? kallas i tick kanske?

};

