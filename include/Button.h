#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <functional>


#include "GUIElement.h"

class Button : public GUIElement
{
	using EventHandler = std::function<void()>;

public:

	Button(sf::Vector2f position, sf::Vector2f btnSize, sf::Color btnColor)
	{
		
		this->btnPosition = position;
		this->btnSize = btnSize;
		this->btnColor = btnColor;

		Set_Base_Layout();
	}
	~Button()
	{
		
		std::cout << "BUTTON_DELETD\n";
	}


	
	void Bind_FuncEvent(EventHandler handler);
	void Set_Size(sf::Vector2f& newSize) override;
	void Set_Base_Color(sf::Color newColor) override;
	void Bind_TextBuilder(Text_Builder& builder);
	bool IsMouseInside(sf::Vector2f mousePos);
	void ButtonClicked(sf::Vector2f mousePos);
	void SetTexture(sf::Texture& texture);
private:

	void Set_Text_Layout() override;
	void Set_Base_Layout() override;
	void Set_Origin_Mid();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	

	sf::RectangleShape rec = sf::RectangleShape();

	sf::Vector2f btnPosition;
	sf::Vector2f btnSize;
	sf::Color btnColor;

	Text_Builder builder = Text_Builder();
	sf::Text text = sf::Text();
	sf::Font font = sf::Font();

	sf::Sprite sprite = sf::Sprite();
	sf::Texture btnTexture = sf::Texture();

	EventHandler eventHandler;
};

