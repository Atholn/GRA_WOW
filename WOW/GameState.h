#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "InstructionState.h"
#include <vector>

class GameState :
	public State
{
private:

	Player* player;
	sf::View view;
	bool shoot = true;

	Enemy* enemy;
	std::vector<Enemy*>::const_iterator iterZ;
	std::vector<Enemy*> *EnemyArray;

	Attack* attack;
	std::vector<Attack*>::const_iterator iterA;
	std::vector<Attack*> *AttackArray;


    Attack* attackE;
	std::vector<Attack*>::const_iterator iterAE;
	std::vector<Attack*> *AttackEArray;

	Coin* coin;
	Coin* bum;
	std::vector<Coin*>::const_iterator iterC;
	std::vector<Coin*> *CoinArray;

	sf::Rect<float> rect;
	
	int x_max, y_max;
	int viewControl =300;
	int xy=0;

	std::vector<Wall*>::const_iterator iterW;
	std::vector<Wall*> *WallArray;
	std::vector<std::vector<int>> mapka;

	Wall* End_door;
	Wall* Start_door;
	Wall* Treasure;
	bool ifTreasure = false;
	
	std::vector<StartArrow*>::const_iterator iterSA;
	StartArrow* startArrow;
	std::vector<StartArrow*> *StartArrowArray;


	
	// zmienne potrzebne do dzialania na czasie  - ataku wroga przy bliskim spotkaniu , ataku wroga na odleglosc oraz ataku gracza 
	sf::Clock clock1;
	sf::Time time1;
	sf::Clock clock2;
	sf::Time time2;
	sf::Clock clock3;
	sf::Time time3;

	int counter = 0, counter2 = 0; // liczniki 

	int end_x, end_y; // 
	int start_x, start_y;
	int gold_x, gold_y;
	int enemy_quantity;
	int lvl; 
	int lvl_max;


	TextDisplay textDisplay;
	std::vector<TextDisplay>::iterator iterT;
	std::vector<TextDisplay> TextDisplayArray;

	sf::Font font;
	sf::Text Hajsy;
	sf::Text HP;
	sf::Text End_text;


	// metody inicjalizujace 
	void initTextures();
	void initPlayers();
	void initEnemy();
	void initWall();
	void initText();
	void initView();
	void initArrow();
	// metody aktualizujace 
	void updateInput(const float& dt);
	void updateEnemy(const float& dt);
	void updateCoinBum(const float& dt);
	void updateAttack(const float& dt);
	void updateAttackE(const float& dt);
	void updateText(const float& dt);
	void updateView(const float& dt);
	void updateEnd(const float& dt);
	void updateArrow(const float& dt);


public:
	GameState(sf::RenderWindow* window,  std::stack<State*>* states,int lvl);
	virtual ~GameState();
	void render(sf::RenderTarget* target);
	void update(const float& dt);
};

#endif