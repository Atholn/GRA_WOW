#ifndef ENTITY_H
#define ENTITY_H



#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>

#include<SFML\System.hpp>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Network.hpp>


class Entity
{
private:
	void initVariables(); // inicjalizacja zmiennych 

public:
	Entity(); // konstruktor
	virtual ~Entity(); // virtualny destruktor 
	sf::Texture* texture; // textura ktora jest dziedziczna w reszcie klas w folderze Entities
	sf::Sprite* sprite; // kszta³t ktory jest dziedziczny w reszcie klas w folderze Entities


	void createSprite(sf::Texture* texture); // kreator  kszta³tu 
	int counterWalking = 0; // licznik do przejsc animacji 

	/// funkcje  podmiotow
	virtual void setPosition(const float x, const float y);  // ustawianie pozycji poczatkowej
	virtual void update(const float& dt) = NULL; // metoda polimorficzna 
	virtual void render(sf::RenderTarget* target); //tworzenie  
};


#endif