#include "Animator.h"

Animator::Animator(std::initializer_list<Animation> vecs){
	for (Animation v : vecs) {
		animations.push_back(v);
	}
	activeTexture = animations[0].get_texture_at(0);
}

//TEMPOR�RT: DENNA �R SPECIFIK F�R PLAYER... KANSKE �R DET EN SUBKLASS AV ANIMATOR F�R OLIKA SORTERS OBJEKT SOM SKA ANIMERAS...
void Animator::change_image(int action) {
	switch (action) {
	case 0:
		activeTexture = animations[0].get_texture_at(0); break; //vanlig
	case 1:
		activeTexture = animations[0].get_texture_at(1); break; //H�GER
	case 2:
		activeTexture = animations[0].get_texture_at(2); break; //v�nster
	}
}

void Animator::draw(Sprite* parent) {
	SDL_RenderCopy(mainWindow.get_ren(), activeTexture, NULL, &parent->get_rect());
}
