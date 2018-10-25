#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Game
{

public:
	/* Singleton Constructor method*/
	static Game& Start();
	~Game() {};

private:

	bool IsExiting();
	void GameLoop();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	GameState* _gameState;
	sf::RenderWindow* _mainWindow;
	
	/* Private constructor for Singleton */
	Game(); 
};
