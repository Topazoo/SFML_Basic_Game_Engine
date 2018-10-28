#pragma once
#include "VisibleGameObject.h"

class GameObjectManager
{
public:
	GameObjectManager() :
		_gameObjects(new std::map<std::string, 
			VisibleGameObject*>) {};

	~GameObjectManager();

	void Add(VisibleGameObject* gameObject);
	void Insert(VisibleGameObject* obj, float xPos, float yPos);

	void Remove(std::string name);
	int GetObjectCount() const;
	VisibleGameObject* Get(std::string name) const;

	void DrawAll(sf::RenderWindow* renderWindow);
	void UpdateAll();

private:
	std::map<std::string, VisibleGameObject*>* _gameObjects;
	sf::Clock clock;

	/* Functor to use during foreach deallocation */
	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject*> & p) const
		{
			delete p.second;
		}
	};

};

