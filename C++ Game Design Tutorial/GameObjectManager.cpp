#include "stdafx.h"
#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}


void GameObjectManager::Add(VisibleGameObject* gameObject)
{
	/* Add an object to the gameobject manager */

	_gameObjects[gameObject->getName()] = gameObject;
}

void GameObjectManager::Remove(std::string name)
{
	/* Remove an object from the gameobject manager */

	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	
	if (results != _gameObjects.end())
	{
		delete results->second;
		_gameObjects.erase(results);
	}
}

VisibleGameObject* GameObjectManager::Get(std::string name) const
{
	/* Retrieve a gameobject from the manager */

	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	
	if (results == _gameObjects.end())
		return NULL;
	
	return results->second;

}

int GameObjectManager::GetObjectCount() const
{
	/* Get the number of stored objects */

	return _gameObjects.size();
}


void GameObjectManager::DrawAll(sf::RenderWindow* renderWindow)
{
	/* Draw all stored objects to screen */

	std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end())
	{
		itr->second->Draw(renderWindow);
		itr++;
	}
}
