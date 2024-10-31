#pragma once
#include <string>
#include "Scene.h"
#include "GameSystem.h"
#include "defines.h"
class GameOverMenu : public Scene
{
public:
	GameOverMenu(short player)
	{
		switch (player)
		{
		case -1:
			this->player = '\0';
			break;
		case Player1:
			this->player = 'x';
			break;

		case Player2:
			this->player = 'o';
			break;
		default:
			assert(false);
			break;
		}

		btn_Array[0] = std::make_unique<Button>(sf::Vector2f(160, 150), sf::Vector2f(180, 60), sf::Color::Blue);
		btn_Array[1] = std::make_unique<Button>(sf::Vector2f(160, 350), sf::Vector2f(180, 60), sf::Color::Blue);
		

		Set_Scene_Layout();
	}
	~GameOverMenu()
	{
		std::cout << "GAME_OVER_MENU_DELETED\n";
	}

private:
	void Set_Scene_Layout() override;
	void Event_Handler(const sf::Event& event) override;

	void Handle_Restart();
	void Handle_MainMenu();

	char player;
	std::array<std::unique_ptr<Button>, 2> btn_Array;
	std::unique_ptr<Text> HeadLine;

};

