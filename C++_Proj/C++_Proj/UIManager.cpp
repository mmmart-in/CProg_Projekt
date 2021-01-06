#include "UIManager.h"
#include "UI_Button.h"
#include "SceneData.h"
#include "GameSystem.h"
#include "UI_Textfield.h"
#include "EnemyHandler.h"
#include "UI_Score.h"
#include "UI_Label.h"
#include <algorithm>
#include <functional>
#include "UI_StartGame.h"

UIManager* UIManager::create_instance(SDL_Renderer* renderer) {
    return new UIManager(renderer);
}

void UIManager::change_page(std::string page_name) {
    auto it = pages.find(page_name);
    if (it != pages.end()) {

        for (auto& component : UI_components)
            delete component;

        UI_components.clear();

        UI_Loader function = it->second;
        (this->*function)();
    }
        
}

void UIManager::handle_interact(SDL_Point point) {
    for (auto& component : UI_components)
        if (SDL_PointInRect(&point, &component->get_rect())) {
            component->interact();
            break;
        }
}

void UIManager::update_UI() {
    for (auto& components : UI_components) 
         components->tick(); 
    for (auto& components : UI_components)
        components->draw();
}

const std::string UIManager::get_active_ui_name() const {
    return active_ui_name;
}

UIManager::UIManager(SDL_Renderer* renderer) : renderer(*renderer) {
    pages.insert(std::make_pair("Menu", &UIManager::create_Menu));
    pages.insert(std::make_pair("Gameplay", &UIManager::create_Gameplay));
    pages.insert(std::make_pair("Options", &UIManager::create_Options));
}

void UIManager::create_Menu() {
    
    UI_Button* start_game = UI_StartGame::create_instance({ 450, 300, 300, 50 }, "Press play", { 255, 255, 255 }, "StartGameplay");
    UI_components.push_back(UI_Label::getInstance({ 300, 100, 600, 100 }, "SPACE INVADERS", { 100, 100, 255 }));
    UI_components.push_back(start_game);
    
}

void UIManager::create_Gameplay() {
    
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

    UI_components.push_back(UI_Score::get_instance(130, 40, 30, 30, 0, { 255, 200, 200, 255 }, *enemy_handler));
    UI_components.push_back(UI_Label::getInstance({ 0, 0, 100, 100 }, "Score", { 255, 255, 255 }));
    
}

void UIManager::create_Options() {

    UI_components.push_back(UI_Label::getInstance({ 450, 50, 300, 50 }, "OPTIONS", { 255, 255, 255 }));
    UI_components.push_back(UI_Label::getInstance({ 150, 150, 50, 50 }, "FPS", { 255, 255, 255 }));
    //UI_components.push_back(UI_Label::getInstance({ 220, 150, 50, 50 }, std::to_string(gameSystem.get_fps()), { 255, 255, 255 }));
    UI_components.push_back(UI_Textfield::create_instance({ 220, 160, 100, 50 }, { 255, 255, 255 }, std::to_string(gameSystem.get_fps())));

}
