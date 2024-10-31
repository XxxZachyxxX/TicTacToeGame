#pragma once
#include <iostream>
#include <filesystem>

#include "RenderManager.h"

class GameSystem
{
public:
	GameSystem()
	{

	}
	virtual ~GameSystem()
	{
		std::cout << "GAME_SYSTEM_DESTROYED\n";
	}
	void StartGameLoop();
	static const std::string GET_PROJECT_PATH(std::string releativePath);
private:
	
};

