
#include "Entity.h"
class Coin :
	public Entity
{
public:
	/// klasa  Coin  maja dwa rodzaje urzytku :
	// z nazwy  czyli klasa ktora oznacza pieniazki
	// oraz uzywam j�  do dzia�ania na wybuchach przy stykni�ciu si� dw�ch atak�w


	bool isCoin = true; // czy jest coinem 
	int coinValue = 5; // wartosc  coina

	int counterLifeTime=0;// licznik 
	int lifeTime = 25; // dlugosc czasu wybuchu
	int direction; // kierunek 


	bool destroy = false; // czy zniszczony, jezeli tak to do usuniecia
	Coin(float x, float y, sf::Texture* texture); // konstruktor 
	void update(const float& dt);  //metoda odpowiedzialna za efekt zderzenia dwoch atakow

};

