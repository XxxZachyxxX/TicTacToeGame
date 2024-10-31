#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <memory>
#include <array>


#include "EventSystem.h"
#include "Layer.h"


#include "Button.h"
#include "Text.h"



class Scene : public EventSystem
{
public:
	Scene()
	{
		
	}
	virtual ~Scene()
	{
		std::cout << "SCENE_DELETED\n";
	}
	
	Layer& GetLayerData();
	std::unique_ptr<Layer> layer = std::make_unique<Layer>();
	virtual void Event_Handler(const sf::Event& event) = 0;

protected:

	bool NewMenu = false;

private:

	virtual void Set_Scene_Layout() = 0;
	

};

