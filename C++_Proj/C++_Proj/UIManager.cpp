#include "UIManager.h"
#include "UI_Page.h"
#include "UI_Button.h"
#include "SceneData.h"
#include "GameSystem.h"
UIManager* UIManager::create_instance(SDL_Renderer* renderer) {
    return new UIManager(renderer);
}

void UIManager::change_page(std::string page_name) {
    for (auto& page : pages)
        if (page->get_page_name(page_name) == page_name)
            active_page = page;
}

UIManager::UIManager(SDL_Renderer* renderer) : active_page(0), renderer(*renderer) {

    UI_Page* menu = UI_Page::create_instance("Menu");
    UI_Page* gameplay = UI_Page::create_instance("Gameplay");
    UI_Page* options = UI_Page::create_instance("Options");

    pages = { menu, gameplay, options };
    
    UI_Button* playButton = new UI_Button(450, 300, 300, 50, NULL, NULL, NULL, "Press here to play", { 100, 255, 255 }, "Play");

    menu->add(playButton);
    menu->add(Label::getInstance(300, 100, 600, 100, "SPACE INVADERS", { 100, 100, 255 }));
    /*  
    menu->add(Label::getInstance(300, 100, 600, 100, "SPACE INVADERS", { 100, 100, 255 }));
    menu->add(
        UIButton<SceneData>::create_instance(450, 300, 300, 50, NULL,
            Label::getInstance(450, 300, 300, 50, "Press here to play!", { 255, 255, 255 }), { *(SceneData::load_gameplay)(5, 7), &sceneData })
    );
    */
    active_page = menu;
    
}
