#include "Game.h"
#include "Utilities.h"

Game::Game()
{
	/* Game constructor - Singleton, only occurs once */

	/* Instantiate and create the game window */
	_mainWindow = new sf::RenderWindow;
	_mainWindow->create(sf::VideoMode(1024, 768, 32), "Pang!");

	/* Instantiate and set the game state */
	_gameState = new Game::GameState;
	*_gameState = Game::Playing;

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

	sf::Event currentEvent;

	/* Poll to check for window closing */
	while (_mainWindow->pollEvent(currentEvent))
	{
		/* Determine logic based on game state */
		switch (*_gameState)
		{
			case Game::Playing: 
			{
				_mainWindow->clear(sf::Color(255, 0, 0));

				/* Display the main window*/
				_mainWindow->display();

				/* If window has been closed, update game state to exit*/
				if (currentEvent.type == sf::Event::Closed)
					*_gameState = Game::Exiting;
				
				break;
			}
		}
	}
}
