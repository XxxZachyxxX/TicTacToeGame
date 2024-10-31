#pragma once
#include "Scene.h"
#include "GameSystem.h"
#include "SceneManager.h"
#include "Game.h"

class ChooseGameMode : public Scene
{
public:
	ChooseGameMode()
	{
		btnArray[0] = std::make_unique<Button>(sf::Vector2f(160, 150), sf::Vector2f(180, 60), sf::Color::Blue);
		btnArray[1] = std::make_unique<Button>(sf::Vector2f(160, 350), sf::Vector2f(180, 60), sf::Color::Blue);

		

		Set_Scene_Layout();
	}
	~ChooseGameMode()
	{
		std::cout << "CHOOSE_GAME_MODE_DELETED\n";
	}
private:
	void Set_Scene_Layout() override;
	void Event_Handler(const sf::Event& event) override;

	void On_Handle_PlayWithAI();
	void On_Handle_PlayWithFriend();
	
	std::array<std::unique_ptr<Button>, 2> btnArray;

	std::unique_ptr<Text> headLine;
};

