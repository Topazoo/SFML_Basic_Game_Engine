#include "MainMenu.h"


MainMenu::MenuResult MainMenu::Show(sf::RenderWindow* window)
{

	/* Display the main menu and responds to button presses */

	/* Load menu image (with buttons drawn in */
	sf::Texture menuImage;
	menuImage.loadFromFile("images/menu/Mainmenu.png");
	sf::Sprite sprite(menuImage);

	/* Create buttons */
	// TODO - Build wrapper class to clean up instantiating buttons

	/* Play button coordinates and action */
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 235;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;

	/* Exit button coordinates and action */
	MenuItem exitButton;
	exitButton.rect.top = 383;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.rect.height = 177;
	exitButton.action = Exit;

	/* Store buttons in list */
	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window->draw(sprite);
	window->display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	/* Look through all stored buttons */
	//TODO - Separate-chaining hash table instead of list
	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		/* If a button is found within the clicked coordinates */
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.top + menuItemRect.height > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.left + menuItemRect.width > x)
		{
			/* Return the action of that button */
			return (*it).action;
		}
	}

	/* If no button within the coordinates, do nothing */
	return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow* window)
{
	sf::Event menuEvent;
	
	/* Infinite loop on menu until user action */
	while (true)
	{

		while (window->pollEvent(menuEvent))
		{
			/* If clicked, check coordinates to see if there's a button there */
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}

			/* If closed, exit game */
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}