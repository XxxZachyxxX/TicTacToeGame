#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <assert.h>


#include "Text_Builder.h"

class GUIElement abstract : sf::Drawable
{
public:
	GUIElement()
	{
		std::cout << "GUI_ELEMENT_CREATED\n";
	}
	virtual ~GUIElement()
	{
		std::cout << "GUI_ELEMENT_DELETED\n";
	}
private:

	virtual void Set_Base_Layout() = 0;
	virtual void Set_Text_Layout() = 0;
	virtual void Set_Size(sf::Vector2f& newSize) = 0;
	virtual void Set_Base_Color(sf::Color newColor) = 0;
	


};

