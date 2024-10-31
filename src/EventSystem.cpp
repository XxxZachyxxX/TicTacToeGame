#include "EventSystem.h"

sf::Event EventSystem::event = sf::Event();
sf::RenderWindow* EventSystem::window = new sf::RenderWindow();
sf::Event& EventSystem::GetEvent()
{
	return event;
}
void EventSystem::Set_Event(const sf::Event& event)
{
	this->event = event;
}
void EventSystem::BindWindow(sf::RenderWindow* window)
{
	this->window = window;

}
sf::Vector2f EventSystem::GetRelativeMousePos()
{
	if (window == nullptr) return sf::Vector2f(0.0f, 0.0f);
	return window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}
void EventSystem::QuitGame()
{
	window->close();
}
