#include "Attack.h"

// Konstruktor ataku
Attack::Attack(float x, float y, sf::Texture* texture)
{
	this->createSprite(texture);
	this->setPosition(x, y);	
}
// Destruktor ataku
Attack::~Attack()
{

}

//Ruch ataku  
void Attack::update(const float& dt)
{
	if (direction == 2)
	{
		this->sprite->setTextureRect(sf::IntRect((counterAnimation/10 ) * 64, 96, 64,32 ));
		this->sprite->move(this->movementSpeed* dt, 0);
	}
	else if (direction == 0)
	{
		this->sprite->setTextureRect(sf::IntRect((counterAnimation/10 ) * 32, 0, 32, 64));
		this->sprite->move(0, this->movementSpeed* dt);
	}
	else if (direction == 3)
	{
		this->sprite->setTextureRect(sf::IntRect((counterAnimation /10) * 32, 128 , 32, 64));
		this->sprite->move(0, -this->movementSpeed * dt);
	}
	else 	if (direction == 1)
	{
		this->sprite->setTextureRect(sf::IntRect((counterAnimation/10 ) * 64, 64, 64, 32));
		this->sprite->move(-this->movementSpeed * dt, 0);
	}
	else
	{

	}

	counterAnimation+=4;
	if (counterAnimation >= 19)
	{
		counterAnimation = 0;
	}
	counterLifeTime++;
	if (counterLifeTime >= lifeTime) destroy = true;
}
