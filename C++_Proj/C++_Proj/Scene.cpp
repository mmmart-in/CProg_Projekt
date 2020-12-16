#include "Scene.h"
#include "Log.h"
Scene::Scene(std::string scene_name, unsigned int scene_index) : scene_name(scene_name), scene_index(scene_index) {
	components = new SceneContents<Component>;
	sprites = new SceneContents<Sprite>;
}

Scene* Scene::create_instance(std::string sceneName, unsigned int scene_index) {
	return new Scene(sceneName, scene_index);
}

const unsigned int Scene::get_scene_index() const {
	return scene_index;
}

const std::string Scene::get_scene_name() const {
	return scene_name;
}


