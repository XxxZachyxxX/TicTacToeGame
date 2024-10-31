#include "GameField.h"

void GameField::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (const auto& item : btnArray)
	{
		target.draw(*(sf::Drawable*)item.get());
	}
	
	target.draw(*fieldBounds);
	

}
void GameField::SetField(short Player, short FieldIndex)
{
	
	
	switch (Player)
	{
		case Player1:
			field[FieldIndex] = 'x';
			btnArray[FieldIndex]->SetTexture(*Player1Sym);
			break;

		case Player2:
			field[FieldIndex] = 'o';
			btnArray[FieldIndex]->SetTexture(*Player2Sym);
			break;

		default:
			assert(false);
			break;
	}
	
}
char* GameField::GetGameField()
{
	return field;
}
bool GameField::IsFieldValid(short i)
{
	if (field[i] == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
bool GameField::Field_Clicked(short currentPlayer, sf::Vector2f mousePos)
{
	for (size_t i = 0; i < btnArray.size(); i++)
	{
		if (btnArray[i]->IsMouseInside(mousePos) && IsFieldValid(i))
		{
			SetField(currentPlayer, i);
			return true;
		}
		
	}
	return false;
}
bool const GameField::CheckWin(char playerSym) const
{
	if (field[0] == playerSym && field[1] == playerSym && field[2] == playerSym)
	{
		return true;
	}
	else if (field[3] == playerSym && field[4] == playerSym && field[5] == playerSym)
	{
		return true;
	}
	else if (field[6] == playerSym && field[7] == playerSym && field[8] == playerSym)
	{
		return true;
	}
	//
	else if (field[0] == playerSym && field[3] == playerSym && field[6] == playerSym)
	{
		return true;
	}
	else if (field[1] == playerSym && field[4] == playerSym && field[7] == playerSym)
	{
		return true;
	}
	else if (field[2] == playerSym && field[5] == playerSym && field[8] == playerSym)
	{
		return true;
	}
	//
	else if (field[0] == playerSym && field[4] == playerSym && field[8] == playerSym)
	{
		return true;
	}
	else if (field[2] == playerSym && field[4] == playerSym && field[6] == playerSym)
	{
		return true;
	}
	
	return false;
}
bool GameField::AI_Clicked_Field(short index)
{
	if (IsFieldValid(index))
	{
		SetField(Player2, index);
		return true;
	}
	return false;
}
void GameField::Change_Color_If_Mouse_Inside(sf::Vector2f mousePos)
{
	for (size_t i = 0; i < btnArray.size(); i++)
	{
		if (btnArray[i]->IsMouseInside(mousePos))
		{
			if (field[i] == '\0')
			{
				btnArray[i]->Set_Base_Color(sf::Color::Green);
			}
			else
			{
				btnArray[i]->Set_Base_Color(sf::Color::Red);
			}
				
				
		}
		else
		{
			btnArray[i]->Set_Base_Color(sf::Color::Transparent);
		}
	}
}
void GameField::Set_Base_Layout()
{
	
	if (!fieldImage->loadFromFile(GameSystem::GET_PROJECT_PATH("Textures\\TicTacToeFieldNew.png")))
	{
		assert(false);
		return;
	}
	
	fieldBounds->setSize(sf::Vector2f(500, 500));
	fieldBounds->setTexture(fieldImage.get());
	
	//Load Symbols

	if (!Player1Sym->loadFromFile(GameSystem::GET_PROJECT_PATH("Textures\\TicTacToeX.png")))
	{
		assert(false);
		return;
	}
	if (!Player2Sym->loadFromFile(GameSystem::GET_PROJECT_PATH("Textures\\TicTacToeO.png")))
	{
		assert(false);
		return;
	}

}
