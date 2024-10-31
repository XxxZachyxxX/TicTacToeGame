#include "Game.h"

void Game::Event_Handler(const sf::Event& event)
{
	gameField->Change_Color_If_Mouse_Inside(GetRelativeMousePos());
	if (GameFinished)
	{
		SceneManager::LoadScene(std::make_unique<MainMenu>());
	}

	while (round != 9 && !GameFinished)
	{
			
			
			switch (currentPlayer)
			{

				case Player1:

					RealPlayerRound(event);
					
					break;

				case Player2:

					if (singlePlayer)
					{
						RealPlayerRound(event);
					}
					else
					{
						AI_Round();

					}
					break;

				default:

					assert(false);

					break;
			}
			
		
		return;
	}
	SceneManager::LoadScene(std::make_unique<GameOverMenu>(-1));
}
bool Game::CheckWin(short player)
{
	switch (player)
	{
		case Player1:
			return gameField->CheckWin('x');
			break;
		case Player2:
			return gameField->CheckWin('o');
			break;
		default:
			assert(false);
			break;
	}
	return false;
}
void Game::RealPlayerRound(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		if (gameField->Field_Clicked(currentPlayer, GetRelativeMousePos()))
		{
			if (CheckWin(currentPlayer))
			{

				SceneManager::LoadScene(std::make_unique<GameOverMenu>(currentPlayer));
				GameFinished = true;
			}
			SwitchPlayer();
		}

	}

	
}
void Game::AI_Round()
{
	if (gameField->AI_Clicked_Field(RandomNumberAlgorithm::GET_NUMBER()))
	{
		RandomNumberAlgorithm::SET_VIRTUAL_FIELD(gameField->GetGameField());
		if (CheckWin(currentPlayer))
		{
			SceneManager::LoadScene(std::make_unique<GameOverMenu>(currentPlayer));
			GameFinished = true;
		}
		SwitchPlayer();
	}
}
void Game::SwitchPlayer()
{
	if (currentPlayer == Player1)
	{
		currentPlayer = Player2;
	}
	else if(currentPlayer == Player2)
	{
		currentPlayer = Player1;
	}
	round++;
}
void Game::Set_Scene_Layout()
{
	gameField = std::make_unique<GameField>();

	layer->background.push_back(gameField.get());
	
}