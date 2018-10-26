#include "Game.h"
#include "Utilities.h"
#include "SplashScreen.h"
#include "MainMenu.h"

Game::Game()
{
	/* Game constructor - Singleton, only occurs once */

	/* Instantiate and create the game window */
	_mainWindow = new sf::RenderWindow;
	_mainWindow->create(sf::VideoMode(1024, 768, 32), "Pang!");

	/* Instantiate and set the game state */
	_gameState = new Game::GameState;
	*_gameState = Game::ShowingSplash;

	/* Loop running game until exit */
	while (!IsExiting())
		GameLoop();

	/* Close the window */
	this->_mainWindow->close();
}

Game& Game::Start()
{
	/* Singleton instantiation of game object */
	
	static Game game;

	return game;
}

bool Game::IsExiting()
{
	/* Check game state for exit condition */

	if (*_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	/* Main game loop */

	/* Determine logic based on game state */
	switch (*_gameState)
	{
		case Game::ShowingSplash:
		{
			ShowSplashScreen();
			break;
		}

		case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}

		case Game::Playing: 
		{
			/* Display the main window*/
			_mainWindow->display();
			_mainWindow->clear(sf::Color(255, 0, 0));

			sf::Event currentEvent;

			/* Poll to check for keyboard or exit events */
			while (_mainWindow->pollEvent(currentEvent))
			{

				/* If window has been closed, update game state to exit*/
				if (currentEvent.type == sf::Event::Closed)
					*_gameState = Game::Exiting;

				if (currentEvent.type == sf::Event::KeyPressed)
				{
					if (currentEvent.key.code == sf::Keyboard::Escape) 
						ShowMenu();
				}
			}
				
			break;
		}
	}
	
}

void Game::ShowSplashScreen()
{
	/* Show the splashscreen */

	SplashScreen splashScreen;

	/* If click or button press, continue to menu */
	if (splashScreen.Show(_mainWindow))
		*_gameState = Game::ShowingMenu;

	/* If exited on splashscreen, exit game */
	else
		*_gameState = Game::Exiting;

}

void Game::ShowMenu()
{
	/* Show the menu */
	MainMenu mainMenu;

	/* Get the result of a click on the menu */
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);

	/* Change game state if button was clicked */
	switch (result)
	{
		case MainMenu::Exit:
			*_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			*_gameState = Game::Playing;
			break;
	}
}
