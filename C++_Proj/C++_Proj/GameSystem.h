#pragma once
#include <vector>
#include "Component.h"
#include "Sprite.h"
#include "Scene.h"
#include <map>
#include "UIManager.h"

#include "MainWindow.h"

class GameSystem {


	public:
		float deltaTime;
		void run();
		GameSystem();
		~GameSystem();
		SDL_Renderer& get_renderer() const;
		const MainWindow& get_current_window();
		void load_new_scene(Scene* newScene, std::string UI);
		Scene* get_current_scene();
		const MainWindow& get_current_window() const;
		template<typename T>void update_active_vector(const std::vector<T*>&, const std::vector<T*>&, std::vector<T*>&);
	private:
		void check_collision();
		void update_components();
		void update_sprites();
		void handle_input();
		void update_scene_objects();
		void change_FPS(int x);

	private:
		//FPS SKA KUNNA ÄNDRAS VIA INMATNINGSFÄLT!?!??!?!?!
		MainWindow* mainWindow;
		int FPS = 60;
		float dur;
		bool running = true;
		Scene* current_scene;
		UIManager* UI_manager;
		std::vector<Sprite*> collision_layers;
		std::vector<Component*> active_components;
		std::vector<Sprite*> active_sprites;
	
};

extern GameSystem gameSystem;

template<typename T>
inline void GameSystem::update_active_vector(const std::vector<T*>& removed, const std::vector<T*>& added, std::vector<T*>& destination) {
	
	for (T* type : removed) {
		auto it = std::find(destination.begin(), destination.end(), type);
		if (it != destination.end()) {
			delete* it;
			destination.erase(it);
		}
	}

	for (T* type : added) {
		std::cout << "added" << std::endl;
		destination.push_back(type);
	}
		
}
