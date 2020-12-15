#include "Scene.h"
#include "Log.h"
Scene::Scene(std::string sceneName, unsigned int scene_index) : scene_name(scene_name), scene_index(scene_index){}

Scene* Scene::create_instance(std::string sceneName, unsigned int scene_index) {
	return new Scene(sceneName, scene_index);
}

void Scene::add_component(Component* component) {
	added_components.push_back(component);
}

void Scene::remove_component(Component* component) {
	removed_components.push_back(component);
}

void Scene::add_sprite(Sprite* sprite) {
	added_sprites.push_back(sprite);
}

void Scene::remove_sprite(Sprite* sprite) {
	removed_sprites.push_back(sprite);
}

void Scene::clear_vectors() {
	added_components.clear();
	added_sprites.clear();
	removed_components.clear();
	removed_sprites.clear();
}

const std::vector<Component*>& Scene::get_added_components() const {
	return added_components;
}

const std::vector<Component*> Scene::get_removed_components() const {
	return removed_components;
}

const std::vector<Sprite*>& Scene::get_added_sprites() const {
	return added_sprites;
}

const std::vector<Sprite*>& Scene::get_removed_sprites() const {
	return removed_sprites;
}

const unsigned int Scene::new_components_size() const {
	return added_components.size();
}

const unsigned int Scene::removed_components_size() const {
	return removed_components.size();
}

const unsigned int Scene::new_sprites_size() const {
	return added_sprites.size();
}

const unsigned int Scene::removed_sprites_size() const {
	return removed_sprites.size();
}

const unsigned int Scene::get_scene_index() const {
	return scene_index;
}

const std::string Scene::get_scene_name() const {
	return scene_name;
}


