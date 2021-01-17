#include "Animator.h"
#include "GameSystem.h"

Animator::Animator(std::vector<Animation*> vecs) {
	for (Animation* v : vecs) {
		animations.push_back(v);
	}
	activeTexture = animations[0]->get_texture_at(0);
	activeInt = 0;
}

Animator::~Animator() {
	SDL_DestroyTexture(activeTexture);
}

Animator::Animator(std::initializer_list<Animation*> vecs){
	for (Animation* v : vecs) {
		animations.push_back(v);
	}
	activeTexture = animations[0]->get_texture_at(0);
	activeInt = 0;
}

void Animator::next_image(int animInt){
	//Här är next image!
	if (activeInt >= animations[animInt]->get_size())
		activeInt = 0;
	activeTexture = animations[animInt]->get_texture_at(activeInt);
	activeInt++;

}

void Animator::draw(Sprite* parent) {
	SDL_RenderCopy(&gameSystem.get_renderer(), activeTexture, NULL, &parent->get_rect());
}
