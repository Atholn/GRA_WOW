#pragma once
#include "Entity.h"
class TextDisplay 
{
public :
	sf::Text text; // zmienna przechowujaca tekst orz odpwoiedzialna za wszystko co sie z nim wiaze 
	sf::Font font; // czcionka
	std::string myString = "Default"; // tekst ktory bêdzie wyswietlany 
	float movementSpeed = 2; // szybkosc "ulatniania"
	
	int counter1 = 0; // licznik 
	int lifeTime = 30; // czas "ulatniania"
	bool destroy = false; // zmienna odpowiedzialna za to czy bêdzie dalej wyswietlany napis

	TextDisplay();
	void update();


};

