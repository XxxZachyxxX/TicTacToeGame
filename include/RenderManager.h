#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "EventSystem.h"
#include "Scene.h"
#include "SceneManager.h"
#include "MainMenu.h"
#include "Layer.h"



class RenderManager
{

public:
	RenderManager()
	{
		StartGameLoop();
	}
	~RenderManager()
	{

	}




private:
	void StartGameLoop();
	sf::RenderWindow* window = nullptr;


};

