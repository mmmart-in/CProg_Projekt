#pragma once

#include "Component.h"
#include "Sprite.h"
#include <vector>
#include <string>

/*************************************************************************
Klassen anv�nds f�r att l�gga till komponenter eller sprites 
under k�rning, GameSystem har tv� egna vektorer som �r "aktiva"
objekt, dvs s�nt som ska visas och uppdateras. GameSystem h�mtar
added_components och added_sprites vid slutet av varje frame och
pushar dessa till sin aktiva vektor. 

Removed �r till f�r objekt som ska tas bort under k�rning, g�r
inte att g�ra delete direkt i t ex Bullet f�r kastar draw() ett
exception (eftersom Bullets f�rsvinner i sin tick-metod). GameSystem
g�r precis som med added fast tar bort det som finns i removed-vektorerna

Blev mycket likadan kod d� Sprite och Component �r tv� olika klassheirarkier.

#BUG#
clear_vectors() tar rensar ALLA vektorer, s� alla skapad scen-data f�rsvinner
vid en ny scen, s� man kan inte ladda tillbaka en gammal scen. Inte mitt smartaste
drag. 
*****************************************************************************/

class Scene{
public:
	static Scene* create_instance(std::string, unsigned int);
	void add_component(Component*);
	void remove_component(Component*);
	void add_sprite(Sprite*);
	void remove_sprite(Sprite*);
	void clear_vectors();
	const std::vector<Component*>& get_added_components() const;
	const std::vector<Component*> get_removed_components() const;
	const std::vector<Sprite*>& get_added_sprites() const;
	const std::vector<Sprite*>& get_removed_sprites() const;
	const unsigned int new_components_size() const;
	const unsigned int removed_components_size() const;
	const unsigned int new_sprites_size() const;
	const unsigned int removed_sprites_size() const;
	const unsigned int get_scene_index() const;
	const std::string get_scene_name() const;
private:
	unsigned int scene_index;
	Scene(std::string, unsigned int);
	std::string scene_name;
	std::vector<Component*> added_components, removed_components;
	std::vector<Sprite*> added_sprites, removed_sprites;
};

