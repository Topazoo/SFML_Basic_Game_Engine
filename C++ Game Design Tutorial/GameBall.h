#pragma once
#include "VisibleGameObject.h"
class GameBall :
	public VisibleGameObject
{
public:
	GameBall(std::string name,
		std::string filename) :
		VisibleGameObject(name, filename) {};
	
	virtual ~GameBall();
};

