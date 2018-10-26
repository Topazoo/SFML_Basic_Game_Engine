#include "StdAfx.h"
#include "SplashScreen.h"

bool SplashScreen::Show(sf::RenderWindow* window)
{
	/* Show a splashscreen */
	sf::Texture splashImage;

	/* Load the splashscreen from an image file */
	if (splashImage.loadFromFile("images/menu/splash2.jpg") != true)
		return false;

	/* Scale the splashscreen to the window size */
	sf::Sprite sprite(splashImage);
	sprite.setScale(1024 / sprite.getLocalBounds().width, 768 / sprite.getLocalBounds().height);
	//TODO - Dynamic resizing with smoothing 
	
	window->draw(sprite);
	window->display();

	sf::Event event;

	/* Infinite loop to keep displaying splashscreen until an event occurs */
	while (true)
	{
		while (window->pollEvent(event))
		{
			/* If clicked or pressed, continue with main game loop */
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed)
			{
				return true;
			}

			/* If closed, exit main game loop */
			else if (event.type == sf::Event::EventType::Closed)
			{
				return false;
			}
		}
	}

	return true;
}