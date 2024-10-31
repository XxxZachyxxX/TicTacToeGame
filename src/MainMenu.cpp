#include "MainMenu.h"


void MainMenu::Set_Scene_Layout()
{
	std::cout << "MAIN_MENU_CREATED\n";
	
	const std::string FONT_PATH = GameSystem::GET_PROJECT_PATH("Lobster\\Lobster-Regular.ttf");

	Text_Builder StartBtn;
	StartBtn.Font_Data_Loc = FONT_PATH;
	StartBtn.C_Size = 30;
	StartBtn.textColor = sf::Color::White;
	StartBtn.Text = "Start";
	StartBtn.offset = 55;
	
	Text_Builder CloseBtn;
	CloseBtn.Font_Data_Loc = FONT_PATH;
	CloseBtn.C_Size = 30;
	CloseBtn.textColor = sf::Color::White;
	CloseBtn.Text = "Close";
	CloseBtn.offset = 55;

	
	btn_Array[0]->Bind_TextBuilder(StartBtn);
	btn_Array[1]->Bind_TextBuilder(CloseBtn);

	btn_Array[0]->Bind_FuncEvent(std::bind(&MainMenu::handleStartGame, this));
	btn_Array[1]->Bind_FuncEvent(std::bind(&MainMenu::handleCloseGame, this));


	Text_Builder HeadLine;
	HeadLine.Font_Data_Loc = FONT_PATH;
	HeadLine.Text = "TicTacToe Game\n";
	HeadLine.textColor = sf::Color::White;

	text->Bind_TextBuiler(HeadLine);

	for (size_t i = 0; i < btn_Array.size(); i++)
	{
		layer->background.push_back((sf::Drawable*)btn_Array[i].get());
	}
	
	
	layer->forground.push_back((sf::Drawable*)text.get());
	

	
	
}
void MainMenu::Event_Handler(const sf::Event& event)
{
	for (size_t i = 0; i < btn_Array.size(); i++)
	{
		if (event.type == sf::Event::MouseMoved)
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
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			if (NewMenu) return;

			//Handle Button Event if clicked
			btn_Array[i]->ButtonClicked(GetRelativeMousePos());
		}
	}

	
}
void MainMenu::handleStartGame()
{
	SceneManager::LoadScene(std::make_unique<ChooseGameMode>());
	NewMenu = true;
}
void MainMenu::handleCloseGame()
{
	QuitGame();
}