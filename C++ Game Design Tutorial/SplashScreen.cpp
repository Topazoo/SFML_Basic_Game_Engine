#include "StdAfx.h"
#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow* window)
{
	sf::Texture splashImage;

	if (splashImage.loadFromFile("images/menu/splash2.jpg") != true)
		return;

	sf::Sprite sprite(splashImage);
	sprite.setScale(1024 / sprite.getLocalBounds().width, 768 / sprite.getLocalBounds().height);
	/* TODO - Dynamic resizing with smoothing */
	window->draw(sprite);
	window->display();

	sf::Event event;
	while (true)
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}