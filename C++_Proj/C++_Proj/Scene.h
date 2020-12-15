#pragma once

#include "Component.h"
#include "Sprite.h"
#include <vector>
#include <string>

/*************************************************************************
Klassen används för att lägga till komponenter eller sprites 
under körning, GameSystem har två egna vektorer som är "aktiva"
objekt, dvs sånt som ska visas och uppdateras. GameSystem hämtar
added_components och added_sprites vid slutet av varje frame och
pushar dessa till sin aktiva vektor. 

Removed är till för objekt som ska tas bort under körning, går
inte att göra delete direkt i t ex Bullet för kastar draw() ett
exception (eftersom Bullets försvinner i sin tick-metod). GameSystem
gör precis som med added fast tar bort det som finns i removed-vektorerna

Blev mycket likadan kod då Sprite och Component är två olika klassheirarkier.

#BUG#
clear_vectors() tar rensar ALLA vektorer, så alla skapad scen-data försvinner
vid en ny scen, så man kan inte ladda tillbaka en gammal scen. Inte mitt smartaste
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

