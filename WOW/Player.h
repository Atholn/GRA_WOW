#include "Entity.h"

class Player :
	public Entity
{
private:

public:

	int directionWalk = true; //zmienna pomocnicza do animacji 
	int direction = 0; // kierunek poruszania 
	int attackDamage = 5;
	int movementSpeed = 100.f; // szybkosc poruszania

	int coins = 0; // zmienna przechowujaca  coiny
	int hp = 100; // zmiena przechowujaca ilosc zycia
	float bX, bY, bD; // zmienne przechowujace poprzednie (before) pozycji x,y oraz kierunku (direction)

	// zmienne umozliwiajace ruch 
	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;

	
	Player(float x, float y, sf::Texture* texture);// konstruktor 
	~Player();
	 void update(const float& dt); // metoda odpowiedzialna za ruch 

};