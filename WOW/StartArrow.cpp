#include "StartArrow.h"
/// ustawienie kierunku
void StartArrow::setDirection(int a)
{
	direction = a;
}
/// konstruktor
StartArrow::StartArrow(float x, float y, sf::Texture * texture)
{
	this->createSprite(texture);
	this->setPosition(x, y);
	this->sprite->setTextureRect(sf::IntRect(0, 0, 64, 64));
}

StartArrow::~StartArrow()
{
}

void StartArrow::update(const float & dt)
{
	switch (direction)
	{
		case 0:this->sprite->move(0, movementSpeed*  dt); break;
		case 1:this->sprite->move(0, -  movementSpeed*  dt); break;
		case 2:this->sprite->move(movementSpeed*  dt, 0); break;
		case 3:this->sprite->move(-movementSpeed * dt, 0); break;
	}

}
