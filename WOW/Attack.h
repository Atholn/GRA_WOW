#include "Entity.h"
class Attack : public Entity // Klasa Attack dziedziczna z klasy Entity
{

public:
	int movementSpeed = 500.f; // szybkosc ataku 
	int attackDamage = 5; //  ilosc obrazen jakie gracz/ stwor bedzie dostawal 
	int direction = 0; // kierunek  1 - do g�ry , 2 - na d� 3- w lewo 4 - w prawo
	int counterAnimation = 0;// licznik odpowiedzialny za zmiane animacji

	int counterLifeTime = 0; // licznik odpowiedzialny za d�ugosc �ycia/lotu  ataku
	int lifeTime = 20; // ogranicznik �ycia ataku

	bool destroy = false;  //zmienna odpowiedzialna za to aby rysowa�/nie rysowa� Ataku
	bool AttackEnemy = false; //false - atak gracza , true - atak potwora

	Attack( float x, float y, sf::Texture* texture); // konstruktor zawieraj�cy pocz�tkow� pozycj� ataku oraz texture kt�ra ma by� rysowana 
	~Attack();

	void update(const float& dt); // metoda odpowiedzialna za ruch ataku
};
