#pragma once
#include "MovableSprite.h"
#include <string>
class Player :
    public MovableSprite
{
public:
    Player(int x, int y, int w, int h, std::string image);

private:
    
    void tick();
    void move();
    void shoot();
    void check_collision(); //??? kallas i tick kanske?
    void draw();

};

