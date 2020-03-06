#include "Coin.h"
// konstruktor
Coin::Coin(float x, float y, sf::Texture* texture)
{
	this->createSprite(texture);
	this->setPosition(x, y);
}

//metoda odpowiedzialna za efekt zderzenia dwoch atakow
void Coin::update(const float& dt)
{
	switch (direction)
	{
	case 0: this->sprite->setTextureRect(sf::IntRect(54, 108, 52, 98)); break;
	case 1: this->sprite->setTextureRect(sf::IntRect(0, 53, 98, 52)); break;
	case 2: this->sprite->setTextureRect(sf::IntRect(0, 0, 98, 52)); break;
	case 3: this->sprite->setTextureRect(sf::IntRect(0, 108, 52, 98)); break;
	}

	///	counterLifeTime++;
	counterLifeTime += 5;
	if (counterLifeTime >= lifeTime) destroy = true;
}