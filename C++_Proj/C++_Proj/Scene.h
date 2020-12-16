#pragma once

#include "Component.h"
#include "Sprite.h"
#include <vector>
#include <string>
#include "SceneContents.h"

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

class Scene {
public:
	static Scene* create_instance();
	SceneContents<Component>* components;
	SceneContents<Sprite>* sprites;
private:
	
	Scene();
	
};

