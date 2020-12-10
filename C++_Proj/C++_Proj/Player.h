#pragma once
#include "MovableSprite.h"
#include <string>
#include "Animator.h"
#include "Animation.h"
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

private:
    int movementSpeed = 5;
    int firePoint = 2;
    int fireCooldown = 500;
    int fireCooldownCount = 0; 
    Animator* anim;
    int forwardAnim = 0;
    int turnRightAnim = 1;
    int turnLeftAnim = 2;
};

