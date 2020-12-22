#pragma once
#include "MovableSprite.h"
#include <string>
#include "Animator.h"
#include "Animation.h"
class Player :
    public MovableSprite
{
public:
    static Player* create_instance(int, int, int, int);
    void move_left();
    void move_right();
    void shoot();
    Collider* get_collider();
    void resolve_collision();
private:
    void tick();
    void check_collision(); //??? kallas i tick kanske?
    void draw();
private:
    Player(int x, int y, int w, int h);
    float moveSpeed = 2;
    int firePoint = 2;
    int fireCooldown = 100;
    Uint32 fireCooldownCount = 0; 
    Animator* anim;
    int forwardAnim = 0;
    int turnRightAnim = 1;
    int turnLeftAnim = 2;
};

