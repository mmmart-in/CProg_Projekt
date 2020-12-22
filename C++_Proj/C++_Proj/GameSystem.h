#pragma once
#include <vector>
#include "Component.h"
#include "Sprite.h"
#include "Scene.h"
#include <map>



class GameSystem {


	public:
		float deltaTime;
		//void add_component(Component*);
		//void add_sprites(Sprite*);
		//void add_to_temp(Sprite*);
		void run();
		GameSystem();
		~GameSystem();
		
		void load_new_scene(Scene* newScene);
		Scene* get_current_scene();
		template<typename T>void update_active_vector(const std::vector<T*>&, const std::vector<T*>&, std::vector<T*>&);
	private:
		void check_collision();
		void update_components();
		void update_sprites();
		void handle_input();
		void update_scene_objects();
		void change_FPS(int x);
	private:
		bool running = true;
		//FPS SKA KUNNA �NDRAS VIA INMATNINGSF�LT!?!??!?!?!
		int FPS = 60;
		
		Scene* current_scene;
		std::map<int, std::vector<Sprite*>> collision_layers;
		std::vector<Component*> active_components;
		std::vector<Sprite*> active_sprites;
		//std::vector<Sprite*> temp;
		float dur;
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
