#pragma once
#include "PlayerPaddle.h"
#include "GameObjectManager.h"

class Game
{

public:
	/* Singleton Constructor method*/
	static Game& Start();
	~Game();

	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

private:

	bool IsExiting();
	void GameLoop();
	void ShowSplashScreen();
	void ShowMenu();
	
	void CreateInitialSprites();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	GameState* _gameState;
	
	sf::RenderWindow* _mainWindow;
	GameObjectManager* _gameObjectManager;
	
	/* Private constructor for Singleton */
	Game(); 
};
