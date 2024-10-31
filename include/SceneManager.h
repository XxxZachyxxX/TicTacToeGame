#pragma once
#include "Scene.h"

class SceneManager
{
public:
	static Scene& GetCurrentScene();
	static void LoadScene(std::unique_ptr<Scene> scene);
	

private:

	static std::unique_ptr<Scene> current_scene;
};

