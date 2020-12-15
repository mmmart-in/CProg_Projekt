#pragma once
#include <vector>
#include "Component.h"
#include "Sprite.h"
#include "Scene.h"
#include <map>

#define FPS 60

class GameSystem {
	public:
		//void add_component(Component*);
		//void add_sprites(Sprite*);
		//void add_to_temp(Sprite*);
		void run();
		~GameSystem();
		void add_new_scenes(std::initializer_list<Scene*>);
		void add_new_scene(Scene*);
		void load_new_scene(unsigned int);
		Scene* get_current_scene();
	private:
		void update_components();
		void update_sprites();
		void handle_input();
		void update_scene_objects();
	private:
		bool running = true;
		Scene* current_scene;
		std::map <unsigned int, Scene*> scene_map;
		std::vector<Component*> active_components;
		std::vector<Sprite*> active_sprites;
		//std::vector<Sprite*> temp;
};

extern GameSystem gameSystem;

