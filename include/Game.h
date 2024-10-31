#pragma once
#include "Scene.h"
#include "GameField.h"
#include "RandomNumberAlgorithm.h"
#include "GameOverMenu.h"

class GameField;

class Game : public Scene
{
public:


	Game(bool singlePlayer)
	{
		this->singlePlayer = singlePlayer;
		Set_Scene_Layout();
	}
	~Game()
	{
		std::cout << "GAME_DELETED\n";
	}

	
private:
	void Set_Scene_Layout() override;
	void Event_Handler(const sf::Event& event) override;
	void SwitchPlayer();
	void RealPlayerRound(const sf::Event& event);
	void AI_Round();
	bool CheckWin(short player);
	CurrentPlayer Player;
	int currentPlayer = 0;
	int round = 0;
	std::unique_ptr<GameField> gameField;
	bool singlePlayer;
	bool GameFinished = false;
};

