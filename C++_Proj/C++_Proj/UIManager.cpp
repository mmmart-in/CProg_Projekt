#include "UIManager.h"
#include "UI_Page.h"
#include "UI_Button.h"
#include "SceneData.h"
#include "GameSystem.h"
#include "Textfield.h"
#include "UI_Menu.h"
#include "UI_Gameplay.h"
#include "Button_StartGame.h"
#include "EnemyHandler.h"
#include "Score.h"
#include "Label.h"
#include <algorithm>
#include "UI_Options.h"
UIManager* UIManager::create_instance(SDL_Renderer* renderer) {
    return new UIManager(renderer);
}

void UIManager::change_page(std::string page_name) {
    auto it = pages.find(page_name);
    if (it != pages.end()) {
        delete active_page;
        Create_Page_Function f = it->second;
        active_page = (this->*f)();
    }
        
}

void UIManager::update_UI() {
    if (active_page) {

        for (auto& components : active_page->get_components()) 
            components->tick();
        
        active_page->draw_UI();
    }
        
}

UIManager::UIManager(SDL_Renderer* renderer) : active_page(0), renderer(*renderer) {
    pages.insert(std::make_pair("Menu", &UIManager::create_Menu));
    pages.insert(std::make_pair("Gameplay", &UIManager::create_Gameplay));
    pages.insert(std::make_pair("Options", &UIManager::create_Options));
}

UI_Page* UIManager::create_Menu() {
    
    UI_Page* menu = new UI_Menu("Menu");
    
    UI_Button* start_game = new Button_StartGame({ 450, 300, 300, 50 }, "Press play", { 255, 255, 255 }, "StartGameplay", 5, 7);

    menu->add(Label::getInstance({ 300, 100, 600, 100 }, "SPACE INVADERS", { 100, 100, 255 }));
    menu->add(start_game);
    
    return menu;
}

UI_Page* UIManager::create_Gameplay() {
    UI_Page* gameplay = UI_Gameplay::create_instance("Gameplay");

    EnemyHandler* enemy_handler = 0;

    //Be till gud att casten lyckas
    for (auto& sprites : gameSystem.get_current_scene()->sprites->get_added()) {
        EnemyHandler* eh = dynamic_cast<EnemyHandler*>(sprites);
        if (eh)
            enemy_handler = eh;
    }

    if (!enemy_handler) {
        for (auto& sprites : gameSystem.get_active_sprites()) {
            EnemyHandler* eh = dynamic_cast<EnemyHandler*>(sprites);
            if (eh)
                enemy_handler = eh;
        }
    }

    gameplay->add(Score::get_instance(130, 40, 30, 30, 0, { 255, 200, 200, 255 }, *enemy_handler));
    gameplay->add(Label::getInstance({ 0, 0, 100, 100 }, "Score", { 255, 255, 255 }));
    
    return gameplay;
}

UI_Page* UIManager::create_Options() {
    auto options = new UI_Options("Options");

    options->add(Label::getInstance({ 450, 50, 300, 50 }, "OPTIONS", { 255, 255, 255 }));
    options->add(Label::getInstance({ 150, 150, 50, 50 }, "FPS", { 255, 255, 255 }));
    options->add(Label::getInstance({ 220, 150, 50, 50 }, std::to_string(gameSystem.get_fps()), { 255, 255, 255 }));

    options->add(Textfield::create_instance({ 210, 145, 100, 50 }, { 255, 255, 0 }));

    return options;

}
