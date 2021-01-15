#include "Scene.h"

Scene::Scene() {
	components = new SceneContents<Component>;
	sprites = new SceneContents<Sprite>;
}

Scene* Scene::create_instance() {
	return new Scene();
}

Scene::~Scene() {
	delete components;
	delete sprites;
}


