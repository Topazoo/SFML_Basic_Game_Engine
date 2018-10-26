#pragma once

class Game
{

public:
	/* Singleton Constructor method*/
	static Game& Start();
	~Game() {};

private:

	bool IsExiting();
	void GameLoop();
	void ShowSplashScreen();
	void ShowMenu();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	GameState* _gameState;
	sf::RenderWindow* _mainWindow;
	
	/* Private constructor for Singleton */
	Game(); 
};
