#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

struct Text_Builder
{
	sf::String Font_Data_Loc = "C:\\Users\\Joel Fritsch\\Downloads\\Lobster\\Lobster-Regular.ttf";
	unsigned short C_Size = 30;
	sf::String Text = "Text";
	sf::Color textColor = sf::Color::White;
	unsigned short offset = 0;
	
};