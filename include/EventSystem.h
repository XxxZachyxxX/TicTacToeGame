#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class EventSystem
{
public:

	EventSystem()
	{
	
	}
	~EventSystem()
	{
		
		std::cout << "EVENT_SYSTEM_DELETED\n";
	}

	void Set_Event(const sf::Event& event);
	void BindWindow(sf::RenderWindow* window);
protected:
	void QuitGame();
	sf::Event& GetEvent();
	sf::Vector2f GetRelativeMousePos();
private:
	
	static sf::Event event;
	static sf::RenderWindow* window;

	

};

