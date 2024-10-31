#include "RenderManager.h"
#include "Scene.h"
#include "MainMenu.h"

void RenderManager::StartGameLoop()
{
	Scene* scene = &SceneManager::GetCurrentScene();

	Layer* layer = &scene->GetLayerData();
	
	window = new sf::RenderWindow(sf::VideoMode(500, 500), "Test", sf::Style::Titlebar | sf::Style::Close);
	
	EventSystem event_System;

	event_System.BindWindow(window);

	sf::Event event;

	window->setFramerateLimit(24);

	while (window->isOpen())
	{
		
		while (window->pollEvent(event))
		{
			
			event_System.Set_Event(event);
			
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}

			SceneManager::GetCurrentScene().Event_Handler(event);
		}
		window->clear();
		layer = &SceneManager::GetCurrentScene().GetLayerData();
		if (layer != nullptr)
		{
			
			for (const auto& item : layer->background)
			{
				window->draw(*item);
			}
			for (const auto& item : layer->forground)
			{
				window->draw(*item);
			}
			for (const auto& item : layer->UI)
			{
				window->draw(*item);
			}
		}
		else
		{
			std::cout << "FATAL_ERROR_LAYER_WAS_NULL\n";
			return;
		}
		

		window->display();
		
	}
}