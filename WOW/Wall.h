#pragma once
#include "Entity.h"
class Wall :
	public Entity
{
public:

	Wall(float x, float y, sf::Texture* texture); // konstruktor
	void update(const float& dt); // metoda aktualizujaca
};

