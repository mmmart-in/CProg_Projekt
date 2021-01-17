#pragma once
#include <vector>
#include "Component.h"
#include "Sprite.h"
#include "Scene.h"
#include <map>
#include "UIManager.h"
#include "SceneData.h"
#include "MainWindow.h"
#include "AudioHandler.h"

class GameSystem {

	public:
		GameSystem();
	
		void run();

		~GameSystem();
		SDL_Renderer& get_renderer() const;
		MainWindow& get_current_window() const;
		Scene& get_current_scene() const;
		SceneData& get_scene_data() const;
		AudioHandler& get_audio_handler() const;

		template<typename T>void update_active_vector(const std::vector<T*>&, const std::vector<T*>&, std::vector<T*>&);
		
		inline const int get_fps() const { return FPS; }
		inline const std::vector<Sprite*>& get_active_sprites() const { return active_sprites; }
		inline UIManager* get_ui_manager() const { return UI_manager; }
		inline void game_over(bool b) { gameover = b; }
		inline const int get_deltatime() const { return deltaTime; }
		void load_new_scene(Scene* newScene, std::string UI);
		
	private:
		
		void check_collision();
		void update_components();
		void update_sprites();
		void handle_input();
		void update_scene_objects();

	private:
		//FPS SKA KUNNA ÄNDRAS VIA INMATNINGSFÄLT!?!??!?!?!
		MainWindow* mainWindow;
		Scene* current_scene;
		SceneData* sceneData;
		UIManager* UI_manager;
		AudioHandler* audioHandler;
		int FPS = 60;
		float dur;
		float deltaTime;
		bool running = true;
		bool gameover = false;
		
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

	for (T* type : added) 
		destination.push_back(type);
	
}
