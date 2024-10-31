#include "Text.h"



void Text::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(text);
}
void Text::Set_Base_Layout()
{
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	
	text.setPosition(textPos);
}
void Text::Set_Text_Layout()
{

	if (!font.loadFromFile(builder.Font_Data_Loc))
	{
		assert(false);
		return;
	}

	text.setFont(font);
	text.setFillColor(builder.textColor);
	text.setString(builder.Text);
	
}
void Text::Set_Size(sf::Vector2f& size)
{

}
void Text::Set_Base_Color(sf::Color color)
{

}
void Text::Bind_TextBuiler(Text_Builder& builder)
{
	this->builder = builder;
	Set_Text_Layout();
}