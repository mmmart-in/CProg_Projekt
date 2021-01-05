#include "UI_Gameplay.h"
#include "Score.h"

UI_Gameplay* UI_Gameplay::create_instance(std::string page_name) {
	return new UI_Gameplay(page_name);
}

UI_Gameplay::UI_Gameplay(std::string page_name) : UI_Page(page_name){}