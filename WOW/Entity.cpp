#include "Entity.h"
// inicjalizacja zmiannych 
void Entity::initVariables()
{
	this->texture = NULL;
	this->sprite = NULL;
}
// konstruktor
Entity::Entity()
{
	this->initVariables();	
}
//destruktor 
Entity::~Entity()
{
	delete this->sprite;
}
// kreator/ ustawianie  textury 
void Entity::createSprite(sf::Texture * texture)
{
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
}

// ustawianie pozycji 
void Entity::setPosition(const float x, const float y)
{
	if (this->sprite)
	{
		this->sprite->setTextureRect(sf::IntRect(0, 0, 32, 32));
		this->sprite->setPosition(x,y);
	}
}

//metoda ruchu aktualizacji inna dla kazdej klasy wiec  uzycie polimorfizmu wskazane 
void Entity::update(const float & dt)
{

}
// rysowanie  rendowanie celu 
void Entity::render(sf::RenderTarget* target)
{
	if (this->sprite)
	{
		target->draw(*this->sprite);
	}
}


