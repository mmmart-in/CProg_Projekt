#include "Animator.h"

Animator::Animator(std::initializer_list<Animation> vecs){
	for (Animation v : vecs) {
		animations.push_back(v);
	}
	activeTexture = animations[0].get_texture_at(0);
}

void Animator::change_image(int action) {
	switch (action) {
	case 1:
		activeTexture = animations[0].get_texture_at(1); break; //HÖGER
	case 2:
		activeTexture = animations[0].get_texture_at(2); break; //vänster
	}
}

void Animator::draw(Sprite* parent) {
	SDL_RenderCopy(mainWindow.get_ren(), activeTexture, NULL, &parent->get_rect());
}
