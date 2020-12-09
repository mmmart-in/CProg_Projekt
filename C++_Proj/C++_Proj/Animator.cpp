#include "Animator.h"

Animator::Animator(std::initializer_list<Animation> vecs) {
	for (Animation v : vecs) {
		texts.push_back(v);
	}
}
