#pragma once
#include <string>
#include "Animator.h"
#include "Animation.h"
#include "Health.h"

class Player : public Sprite
{
public:
    static Player* create_instance(int, int, int, int);
    
    void shoot();
    
    void resolve_collision();
    ~Player();

private:
    Player(int x, int y, int w, int h);
    void tick();
    void draw();
    void handle_input();
    void move_left();
    void move_right();

private:
    int forwardAnim = 0;
    int turnRightAnim = 1;
    int turnLeftAnim = 2;
    int firePoint = 2;
    int fireCooldown = 100;
    int tickCount = 0;
    bool hitCooldown = false;
    float moveSpeed = 4;
    Uint32 fireCooldownCount = 0; 
    Animator* anim;
    Health* hp;
    
};

