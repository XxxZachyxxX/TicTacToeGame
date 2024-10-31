#include "Button.h"
#include <string>

void Button::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	
	target.draw(rec);
	target.draw(sprite);
	if (text.getFont() == nullptr) return;
	target.draw(text);
}

void Button::Set_Base_Layout()
{
	//Build my Button


	Set_Origin_Mid();
	rec.setSize(btnSize);
	rec.setPosition(btnPosition);
	rec.setFillColor(btnColor);


}
void Button::Set_Text_Layout()
{
	//Build my Text

	if(!font.loadFromFile(builder.Font_Data_Loc))
	{
		std::cout << "FILE_FONT_NOT_FOUND\n";
		return;
	}
	text.setFont(font);
	text.setString(builder.Text);
	text.setCharacterSize(builder.C_Size);
	text.setFillColor(builder.textColor);
	
	/*text->setOrigin(rec->getGlobalBounds().width / 2, rec->getGlobalBounds().height / 2);*/
	text.setPosition(rec.getPosition().x + builder.offset, rec.getPosition().y);
	
}
void Button::Set_Size(sf::Vector2f& newSize)
{
	rec.setSize(newSize);
}
void Button::Set_Base_Color(sf::Color newColor)
{
	rec.setFillColor(newColor);
}
void Button::Set_Origin_Mid()
{
	
	rec.setOrigin(rec.getGlobalBounds().width / 2, rec.getGlobalBounds().height / 2);
	
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}
void Button::Bind_TextBuilder(Text_Builder& builder)
{
	this->builder = builder;
	Set_Text_Layout();
}
void Button::Bind_FuncEvent(EventHandler handler)
{
	this->eventHandler = handler;
}
bool Button::IsMouseInside(sf::Vector2f mousePos)
{
	if (rec.getGlobalBounds().contains(mousePos))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Button::ButtonClicked(sf::Vector2f mousePos)
{
	
	if (rec.getGlobalBounds().contains(mousePos))
	{
		eventHandler();
	}
}
void Button::SetTexture(sf::Texture& texture)
{
	
	sprite.setTexture(texture, false);
	sf::FloatRect scale = sprite.getLocalBounds();
	sprite.setScale(sf::Vector2f(rec.getSize().x / scale.width, rec.getSize().y / scale.height));
	sprite.setPosition(rec.getPosition());
	
}
