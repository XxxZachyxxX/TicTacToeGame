#pragma once

#include <iostream>
#include <assert.h>
#include <array>

#include "GUIElement.h"
#include "Button.h"
#include "defines.h"
#include "GameSystem.h"



class GameField : public sf::Drawable
{
public:

	GameField()
	{
		btnArray[0] = std::make_unique<Button>(sf::Vector2f(0, 0), BTN_SIZE_SQUARE, sf::Color::Transparent);
		btnArray[1] = std::make_unique<Button>(sf::Vector2f(166, 0), BTN_SIZE_SQUARE, sf::Color::Transparent);
		btnArray[2] = std::make_unique<Button>(sf::Vector2f(343, 0), BTN_SIZE_SQUARE, sf::Color::Transparent);

		btnArray[3] = std::make_unique<Button>(sf::Vector2f(0, 166), BTN_SIZE_SQUARE, sf::Color::Transparent);
		btnArray[4] = std::make_unique<Button>(sf::Vector2f(166, 166), BTN_SIZE_SQUARE, sf::Color::Transparent);
		btnArray[5] = std::make_unique<Button>(sf::Vector2f(343, 166), BTN_SIZE_SQUARE, sf::Color::Transparent);

		btnArray[6] = std::make_unique<Button>(sf::Vector2f(0, 343), BTN_SIZE_SQUARE, sf::Color::Transparent);
		btnArray[7] = std::make_unique<Button>(sf::Vector2f(166, 343), BTN_SIZE_SQUARE, sf::Color::Transparent);
		btnArray[8] = std::make_unique<Button>(sf::Vector2f(343, 343), BTN_SIZE_SQUARE, sf::Color::Transparent);
		
		for (size_t i = 0; i < btnArray.size(); i++)
		{
			field[i] = '\0';
		}
		Set_Base_Layout();
	}
	~GameField()
	{
		
		std::cout << "GAME_FIELD_DELETED\n";
		
	}

	void SetField(short Player, short fieldIndex);
	bool IsFieldValid(short i);
	void Change_Color_If_Mouse_Inside(sf::Vector2f mousePos);
	bool Field_Clicked(short currentPlayer, sf::Vector2f mousePos);
	char* GetGameField();
	bool AI_Clicked_Field(short i);
	bool const CheckWin(char playerSym) const;

private:
	void Set_Base_Layout();

	std::unique_ptr<sf::Texture> fieldImage = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::RectangleShape> fieldBounds = std::make_unique<sf::RectangleShape>();
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	std::unique_ptr<sf::Texture> Player1Sym = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> Player2Sym = std::make_unique<sf::Texture>();
	std::array<std::unique_ptr<Button>, 9> btnArray;
	const sf::Vector2f BTN_SIZE_SQUARE = sf::Vector2f(157, 157);
	
	char field[9];

};

