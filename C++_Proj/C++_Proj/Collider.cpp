#include "Collider.h"


Collider::Collider(int x, int y, int w, int h) :
	x(x), y(y), w(w), h(h) {

}

Collider::~Collider() {

}

/*
//Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

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