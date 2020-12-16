#include "Scene.h"
#include "Log.h"
Scene::Scene() {
	components = new SceneContents<Component>;
	sprites = new SceneContents<Sprite>;
}

Scene* Scene::create_instance() {
	return new Scene();
}




