#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "ChooseGameMode.h"
#include "GameSystem.h"

class MainMenu : public Scene
{
public:

	MainMenu()
	{

		btn_Array[0] = std::make_unique<Button>(sf::Vector2f(160, 150), sf::Vector2f(180, 60), sf::Color::Blue);
		btn_Array[1] = std::make_unique<Button>(sf::Vector2f(160, 350), sf::Vector2f(180, 60), sf::Color::Blue);
		text = std::make_unique<Text>(sf::Vector2f(152, 40));

		Set_Scene_Layout();
	}
	~MainMenu()
	{
		
		std::cout << "MAIN_MENU_DELETED\n";
	}
	
private:
	void handleStartGame();
	void handleCloseGame();
	void Set_Scene_Layout() override;
	void Event_Handler(const sf::Event& event) override;
	std::array<std::unique_ptr<Button>, 2> btn_Array;
	std::unique_ptr<Text> text;


};

