#include "ChooseGameMode.h"
#include "Button.h"


void ChooseGameMode::Set_Scene_Layout()
{	
	
	const std::string FONT_PATH = GameSystem::GET_PROJECT_PATH("Lobster\\Lobster-Regular.ttf");
	Text_Builder PlayWithAI;
	PlayWithAI.Font_Data_Loc = FONT_PATH;
	PlayWithAI.C_Size = 30;
	PlayWithAI.textColor = sf::Color::White;
	PlayWithAI.Text = "Play with AI";
	PlayWithAI.offset = 17;
	

	Text_Builder PlayWithFriend;
	PlayWithFriend.Font_Data_Loc = FONT_PATH;
	PlayWithFriend.C_Size = 27;
	PlayWithFriend.textColor = sf::Color::White;
	PlayWithFriend.Text = "Play with Friend";
	
	Text_Builder HeadLine;
	HeadLine.C_Size = 35;
	HeadLine.Font_Data_Loc = FONT_PATH;
	HeadLine.Text = "Choose your Game Mode:";

	headLine = std::make_unique<Text>(sf::Vector2f(40, 20));
	headLine->Bind_TextBuiler(HeadLine);

	btnArray[0]->Bind_TextBuilder(PlayWithFriend);
	btnArray[1]->Bind_TextBuilder(PlayWithAI);
	
	btnArray[0]->Bind_FuncEvent(std::bind(&ChooseGameMode::On_Handle_PlayWithAI, this));
	btnArray[1]->Bind_FuncEvent(std::bind(&ChooseGameMode::On_Handle_PlayWithFriend, this));

	
	for (size_t i = 0; i < btnArray.size(); i++)
	{
		layer->background.push_back((sf::Drawable*)btnArray[i].get());
	}
	layer->background.push_back((sf::Drawable*)headLine.get());

}
void ChooseGameMode::Event_Handler(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		for (size_t i = 0; i < btnArray.size(); i++)
		{
			if (btnArray[i]->IsMouseInside(GetRelativeMousePos()))
			{
				btnArray[i]->Set_Base_Color(sf::Color::Cyan);
			}
			else
			{
				btnArray[i]->Set_Base_Color(sf::Color::Blue);
			}
		}
		
	}
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		for (size_t i = 0; i < btnArray.size(); i++)
		{
			if (NewMenu) return;
			btnArray[i]->ButtonClicked(GetRelativeMousePos());
		}
	}
	

}
void ChooseGameMode::On_Handle_PlayWithFriend()
{
	NewMenu = true;
	SceneManager::LoadScene(std::make_unique<Game>(false));
}
void ChooseGameMode::On_Handle_PlayWithAI()
{
	NewMenu = true;
	SceneManager::LoadScene(std::make_unique<Game>(true));
	
}
