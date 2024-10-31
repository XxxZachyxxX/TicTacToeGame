#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
struct Layer
{
	std::vector<sf::Drawable*> background;
	std::vector<sf::Drawable*> forground;
	std::vector<sf::Drawable*> UI;

	~Layer()
	{	
		std::cout << "LAYER_DELETED\n";
	}
};