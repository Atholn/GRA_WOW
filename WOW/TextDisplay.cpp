#include "TextDisplay.h"

TextDisplay::TextDisplay()
{
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(25);
	text.setString(myString);
}



void TextDisplay::update()
{
	text.move(0, -movementSpeed);
	counter1++;
	if (counter1 >= lifeTime)
	{
		destroy = true;
	}

}

