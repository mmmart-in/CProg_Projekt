#pragma once
#include "FixedSprite.h"
class Castle :
    public FixedSprite
{
public:
    Castle(int x, int y, int w, int h);
    ~Castle();

    void draw();
};

