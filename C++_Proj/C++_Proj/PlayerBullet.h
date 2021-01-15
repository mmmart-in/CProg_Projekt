#pragma once
#include "Bullet.h"
#include "GameSystem.h"
class PlayerBullet : public Bullet {
public:
    static PlayerBullet* get_instance(int x, int y, int w, int h);
    ~PlayerBullet() = default;
    void move();
    void tick();
private:
    PlayerBullet(int x, int y, int w, int h);
};

