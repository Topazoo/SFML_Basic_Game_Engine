#pragma once
#include "VisibleGameObject.h"

class PlayerPaddle :
	public VisibleGameObject
{
public:
	PlayerPaddle(std::string name, 
		std::string filename) : 
		VisibleGameObject(name, filename), 
		_velocity(0), _maxVelocity(600) {};

	void Update(float elapsedTime);

	~PlayerPaddle();

private:
	float GetVelocity() const;

private:
	float _velocity;  // -- left ++ right
	float _maxVelocity;
};

