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

//vene om detta �r r�tt men n�tt s�nt.. den h�r kallas n�r man vill loopa en animation.. "x" �r d� vilken animation man vill loopa genom
void Animator::animate_loop(int x) {
	for (int i = 0; i < animations[x].get_size(); i++) {
		//g�r ett if h�r f�r att kolla att det �r dags att byta bild.. tickCount % 20 eller n�t
		activeTexture = animations[x].get_texture_at(i);
		if (i <= animations[x].get_size())
			i = 0;
	}

}
//en till funktion som bara k�r igenom en animation och sen g�r vidare.. h�r m�ste man skicka in en int f�r att s�ga
//vilken animation man ska k�ra igenom och sen den andra inten f�r att s�ga vart den ska h�rn�st.
//detta kanske bara �r svammel... men tror n�tt s�nt h�r borde funka.

void Animator::draw(Sprite* parent) {
	SDL_RenderCopy(mainWindow.get_ren(), activeTexture, NULL, &parent->get_rect());
}
