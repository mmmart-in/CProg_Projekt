#include "UI_Options.h"
#include "Textfield.h"
UI_Options::UI_Options(std::string page_name) : UI_Page(page_name){}

void UI_Options::interact_with(Component* component) {
	std::cout << "interac" << std::endl;
	Textfield* textfield = dynamic_cast<Textfield*>(component);
	if (textfield)
		textfield->run();
}
