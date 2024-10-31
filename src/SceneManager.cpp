#include "SceneManager.h"

std::unique_ptr<Scene> SceneManager::current_scene = nullptr;

Scene& SceneManager::GetCurrentScene()
{
	return *current_scene;
}
void SceneManager::LoadScene(std::unique_ptr<Scene> scene)
{
	SceneManager::current_scene = std::move(scene);
	
}