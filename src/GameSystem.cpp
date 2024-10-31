#include "GameSystem.h"

void GameSystem::StartGameLoop()
{

	
	SceneManager::LoadScene(std::make_unique<MainMenu>());
	RenderManager Render_Manager = RenderManager();

	
	
}
const std::string GameSystem::GET_PROJECT_PATH(std::string releativePath)
{
	
	
	std::filesystem::path currentPath = std::filesystem::current_path();
	std::filesystem::path basePath = currentPath / "Resources";
	std::filesystem::path fullPath = basePath / releativePath;

	return fullPath.string();

}