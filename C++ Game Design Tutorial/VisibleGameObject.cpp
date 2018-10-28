#include "stdafx.h"
#include "VisibleGameObject.h"

VisibleGameObject::~VisibleGameObject()
{
	delete _sprite;
	delete _image;
}

void VisibleGameObject::Load(float xPos, float yPos)
{
	/* If the image for the sprite is valid, load and set position*/

	if (_image->loadFromFile(_filename) != false)
	{
		_sprite->setTexture(*_image);
		_sprite->setPosition(xPos, yPos);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow* renderWindow)
{
	/* Draw the object sprite */

	if (_isLoaded)
		renderWindow->draw(*_sprite);
}

void VisibleGameObject::Update(float elapsedTime)
{
}

void VisibleGameObject::SetPosition(float x, float y)
{
	/* Set the object sprite position */

	if (_isLoaded)
		_sprite->setPosition(x, y);
}

sf::Vector2f VisibleGameObject::GetPosition() const
{
	if (_isLoaded)
		return _sprite->getPosition();

	return sf::Vector2f();
}

sf::Sprite* VisibleGameObject::GetSprite()
{
	if (_isLoaded)
		return _sprite;

	return nullptr;
}

