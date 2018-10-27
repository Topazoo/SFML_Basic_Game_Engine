#include "stdafx.h"
#include "VisibleGameObject.h"



VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::Load()
{
	if (_image.loadFromFile(_filename) != false)
	{
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow* renderWindow)
{
	if (_isLoaded)
	{
		renderWindow->draw(_sprite);
	}
}

void VisibleGameObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}
