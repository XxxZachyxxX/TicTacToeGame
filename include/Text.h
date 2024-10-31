#pragma once
#include "GUIElement.h"

class Text : public GUIElement
{
public:
	Text(sf::Vector2f textPos)
	{
		this->textPos = textPos;
		Set_Base_Layout();
	}
	~Text()
	{
		std::cout << "TEXT_DELETED\n";
	}
	void Bind_TextBuiler(Text_Builder& builder);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	void Set_Base_Layout() override;
	void Set_Text_Layout() override;
	void Set_Size(sf::Vector2f& size) override;
	void Set_Base_Color(sf::Color color) override;


	Text_Builder builder = Text_Builder();
	sf::Text text = sf::Text();
	sf::Font font = sf::Font();

	sf::Vector2f textPos;

};

