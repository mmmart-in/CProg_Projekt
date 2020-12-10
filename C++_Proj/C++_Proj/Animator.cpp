#include "Animator.h"

Animator::Animator(std::initializer_list<Animation> vecs){
	for (Animation v : vecs) {
		animations.push_back(v);
	}
	activeTexture = animations[0].get_texture_at(0);
}

//vene om detta är rätt men nått sånt.. den här kallas när man vill loopa en animation.. "x" är då vilken animation man vill loopa genom
void Animator::animate_loop(int x) {
	for (int i = 0; i < animations[x].get_size(); i++) {
		//gör ett if här för att kolla att det är dags att byta bild.. tickCount % 20 eller nåt
		activeTexture = animations[x].get_texture_at(i);
		if (i <= animations[x].get_size())
			i = 0;
	}

}
//en till funktion som bara kör igenom en animation och sen går vidare.. här måste man skicka in en int för att säga
//vilken animation man ska köra igenom och sen den andra inten för att säga vart den ska härnäst.
//detta kanske bara är svammel... men tror nått sånt här borde funka.


void Animator::draw(Sprite* parent) {
	SDL_RenderCopy(mainWindow.get_ren(), activeTexture, NULL, &parent->get_rect());
}
