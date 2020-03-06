#pragma once
#include "Entity.h"
#include "Random.h"

class Enemy :
	public Entity
{


private:

public:
	// zmienne
	int movementSpeed = 15; // szybkosc ruchu
	int movmentLength = 30; // dlugosc ruchu w danym kierunku 
	int attackDamage = 2; // wartosc ataku
	bool blokada = true; // blokada czy atakuje 
	bool directionWalk = true; // zmienna pomocnicza do animacji
	int direction = 0;// kierunek  1- up , 2 - dol 3- left 4 right
	int counter = 0; // licznik do zmiany kierunku ruchu
	int hp = 10; // zycie zombiaka

	bool alive = true; // czy jest zywy
	// blokady zderzen z murem 
	bool canMoveUp = true; 
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;



	Enemy(float x, float y, sf::Texture* texture); // konstruktor

	void update(const float & dt); // metoda aktualizujaca

};





