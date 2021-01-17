#ifndef SCENEDATA_H
#define SCENEDATA_H

#include "Scene.h"
class SceneData
{
public:
	Scene* load_menu();
	Scene* load_gameplay(int r, int c);
};

#endif