#include "Enemy.h"

// konstruktor
Enemy::Enemy(float x, float y, sf::Texture* texture)
{
	this->createSprite(texture);
	this->setPosition(x, y);
}
// metoda aktualizujaca ruch i animacje
void Enemy::update(const float& dt)
{
		if (direction == 2)
		{
			if (canMoveRight == true)
			{
				this->sprite->setTextureRect(sf::IntRect((counterWalking / 10) * 32, 32 * direction, 32, 32));
				this->sprite->move(this->movementSpeed* dt, 0);

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
			this->sprite->setTextureRect(sf::IntRect((counterWalking / 10) * 32, 32 * direction, 32, 32));
			this->sprite->move( -this->movementSpeed* dt, 0);
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
			}
		}
		else if (direction == 0)
		{
			if (canMoveDown == true)
			{
			this->sprite->setTextureRect(sf::IntRect((counterWalking / 10) * 32, 32 * 0, 32, 32));
			this->sprite->move(0 ,  this->movementSpeed * dt);
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
			}
		}
		else 	if (direction == 3)
		{
			if (canMoveUp == true)
			{
			this->sprite->setTextureRect(sf::IntRect((counterWalking / 10) * 32, 32 * direction, 32, 32));
			this->sprite->move(0, -this->movementSpeed * dt);
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
			}
		}
		else
		{
		}
		if (directionWalk)
			counterWalking += 3;
		else
			counterWalking -= 3;

		if (counterWalking >= 29) { counterWalking = 29; directionWalk = false; }
		else if (counterWalking <= 0) { counterWalking = 0; directionWalk = true; }

	counter++;
	if ( blokada)
	if (counter >= movmentLength)
	{
		direction = generateRandom(4)-1;
		counter = 0;
	}
	
}

