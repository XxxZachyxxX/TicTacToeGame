#include "GameOverMenu.h"


void GameOverMenu::Set_Scene_Layout()
{
	const std::string PATH = GameSystem::GET_PROJECT_PATH("Lobster\\Lobster-Regular.ttf");
	Text_Builder BtnRestart;
	BtnRestart.textColor = sf::Color::White;
	BtnRestart.Font_Data_Loc = PATH;
	BtnRestart.Text = "Play Again";
	BtnRestart.offset = 20;


	Text_Builder BtnMainMenu;
	BtnMainMenu.Font_Data_Loc = PATH;
	BtnMainMenu.textColor = sf::Color::White;
	BtnMainMenu.Text = "Go to MainMenu";
	BtnMainMenu.C_Size = 27;

	btn_Array[0]->Bind_TextBuilder(BtnRestart);
	btn_Array[1]->Bind_TextBuilder(BtnMainMenu);

	HeadLine = std::make_unique<Text>(sf::Vector2f(160, 50));
	Text_Builder HeadLineBuilder;
	HeadLineBuilder.Font_Data_Loc = PATH;
	HeadLineBuilder.textColor = sf::Color::White;

	std::string result;

	if (player == '\0')
	{
		result = "Nobody Won :(";
	}
	else
	{
		result = std::string("Player: ") + player + std::string(" Won");
	}

	
	HeadLineBuilder.Text = result;


	HeadLine->Bind_TextBuiler(HeadLineBuilder);


	btn_Array[0]->Bind_FuncEvent(std::bind(&GameOverMenu::Handle_Restart, this));
	btn_Array[1]->Bind_FuncEvent(std::bind(&GameOverMenu::Handle_MainMenu, this));

	for (const auto& item : btn_Array)
	{
		layer->background.push_back((sf::Drawable*)item.get());
	}
	layer->forground.push_back((sf::Drawable*)HeadLine.get());

}
void GameOverMenu::Event_Handler(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		for (size_t i = 0; i < btn_Array.size(); i++)
		{
			if (btn_Array[i]->IsMouseInside(GetRelativeMousePos()))
			{
				btn_Array[i]->Set_Base_Color(sf::Color::Cyan);
			}
			else
			{
				btn_Array[i]->Set_Base_Color(sf::Color::Blue);
			}
		}
	}
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		for (size_t i = 0; i < btn_Array.size(); i++)
		{
			if (NewMenu) return;
			if (btn_Array[i]->IsMouseInside(GetRelativeMousePos()))
			{
				
				btn_Array[i]->ButtonClicked(GetRelativeMousePos());
			}
			
		}
	}
}
void GameOverMenu::Handle_Restart()
{
	SceneManager::LoadScene(std::make_unique<ChooseGameMode>());
	NewMenu = true;
}
void GameOverMenu::Handle_MainMenu()
{
	
	SceneManager::LoadScene(std::make_unique<MainMenu>());
	NewMenu = true;
}
