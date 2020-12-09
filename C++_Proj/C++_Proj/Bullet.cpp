#include "Bullet.h"


Bullet::Bullet(int x, int y, int w, int h, std::string image) :
	MovableSprite(x, y, w, h, image) {

}

Bullet::~Bullet() {
<<<<<<< Updated upstream


}

void Bullet::tick() {
=======
	
}

void Bullet::tick() {
	rect.y--;
}
>>>>>>> Stashed changes

}