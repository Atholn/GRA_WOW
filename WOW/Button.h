#ifndef BUTTON_H
#define BUTTON_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>

#include<SFML\System.hpp>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Network.hpp>

enum button_states{BTN_IDLE , BTN_HOVER, BTN_ACTIVE };


class Button
{
private:
	short unsigned buttonState;


	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;


public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text,
		sf::Color idleColor, sf::Color hoverolor, sf::Color activeColor);
	~Button();
	bool Block=false;
	bool activ = false;
	/// accessors
	const bool isPressed() const;


	/// funkcje
	void update(const sf::Vector2f mousePos);
	void update(bool activ);
	void render(sf::RenderTarget * target);
};

#endif