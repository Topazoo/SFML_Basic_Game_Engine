#include "stdafx.h"
#include "PlayerPaddle.h"
#include "Game.h"

PlayerPaddle::~PlayerPaddle()
{
}

float PlayerPaddle::GetVelocity() const
{
	return _velocity;
}

void PlayerPaddle::Update(float elapsedTime)
{
	/* Update velocity based on keypress */

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		_velocity = -300.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		_velocity = 300.0f;

	//else //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		//_velocity = 0.0f;

	/* Ensure velocity is capped */
	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;

	if (_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;


	sf::Vector2f pos = this->GetPosition();

	/* Ensure object is within window borders */
	if (pos.x - GetSprite()->getLocalBounds().width / 2 < 0)
		_velocity = 20;
	else if (pos.x + GetSprite()->getLocalBounds().width / 2 > Game::SCREEN_WIDTH)
		_velocity = -20;

	/* Update position based on velocity */
	GetSprite()->move(_velocity * elapsedTime, 0);
	_velocity = 0.0f;
}
