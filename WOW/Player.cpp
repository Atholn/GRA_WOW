#include "Player.h"


// konstruktor
Player::Player(float x, float y,  sf::Texture* texture)
{
	this->createSprite(texture);
	this->setPosition(x, y);
}

Player::~Player()
{
}

//aktualizacja ruchu gracza
void Player::update(const float& dt)
{
	if (this->sprite)
	{
		if ( direction == 3)
		{  
			if (canMoveUp == true)
			{
				this->sprite->setTextureRect(sf::IntRect((counterWalking / 10) * 32, 32 * 3, 32, 32));
				this->sprite->move(0, -this->movementSpeed * dt);

				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;
			}
		}
		else if (direction == 2)
		{
			if (canMoveRight == true)
			{
				this->sprite->setTextureRect(sf::IntRect((counterWalking / 10) * 32, 32 * 2, 32, 32));
				this->sprite->move(this->movementSpeed * dt, 0);
				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;
			}
		}
		else if (direction == 1)
		{
			if (canMoveLeft == true)
			{
				this->sprite->setTextureRect(sf::IntRect((counterWalking / 10) * 32, 32 * 1, 32, 32));
				this->sprite->move(-this->movementSpeed* dt, 0);
				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;

			}
		}
		else 	if (direction == 0)
		{
			if (canMoveDown == true)
			{
				this->sprite->setTextureRect(sf::IntRect((counterWalking / 10) * 32, 32 * 0, 32, 32));
				this->sprite->move(0, this->movementSpeed * dt);
				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;
				this->sprite->move(0, 0);
			}
		}
		else
		{
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
		}
		

	}

	if (directionWalk)
	counterWalking += 6;
	else 
		counterWalking -= 6;

	if (counterWalking >= 29) { counterWalking = 29; directionWalk = false; }
	else if (counterWalking <=0) {  counterWalking = 0; directionWalk = true; } 
}

