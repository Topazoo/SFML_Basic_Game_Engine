#pragma once
#include "VisibleGameObject.h"

class PlayerPaddle :
	public VisibleGameObject
{
public:
	PlayerPaddle(std::string name, 
		std::string filename) : 
		VisibleGameObject(name, filename) {};

	~PlayerPaddle();
};

