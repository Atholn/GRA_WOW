#include "Wall.h"


/// konstruktor
Wall::Wall(float x, float y, sf::Texture * texture)
{
	this->createSprite(texture);
	this->setPosition(x, y);
}
// metoda aktualizujaca , nie zawiera zadnego dzialania poniewaz mur tylko stoi 
void Wall::update(const float & dt)
{
}
