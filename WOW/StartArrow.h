#pragma once
#include "Entity.h"
class StartArrow :
	public Entity
{

	float movementSpeed =200;
	int direction;


public:
	
	void setDirection(int a);
	bool destroy = false;
	StartArrow(float x, float y, sf::Texture* texture);// konstruktor 
	~StartArrow();
	void update(const float& dt); // metoda odpowiedzialna za ruch 

};

