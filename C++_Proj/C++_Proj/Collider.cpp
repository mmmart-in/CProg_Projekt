#include "Collider.h"


Collider::Collider(int x, int y, int w, int h) :
	x(x), y(y), w(w - 15), h(h-10) {

}

Collider::~Collider() {

}

/*
    leftA = x;
    rightA = x + w;
    topA = y;
    bottomA = y + h;
*/

bool Collider::check_collision(const Collider& other) {
    //bottom <= otherTop
    if (y + h <= other.y)
        return false;
    //Top >= otherBottom
    if (y >= other.y + other.h)
        return false;
    //right <= otherLeft
    if (x + w <= other.x)
        return false;
    //left >= otherRight
    if (x >= other.x + other.w)
        return false;

    return true;
}