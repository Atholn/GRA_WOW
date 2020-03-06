#ifndef STATE_H
#define STATE_H

#include "Button.h"
#include"Player.h"
#include"Enemy.h"
#include"Attack.h"
#include"Coin.h"
#include"Wall.h"
#include"StartArrow.h"
#include"TextDisplay.h"



class State
{
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;

	bool quit;

	
	std::map<std::string, sf::Texture> textures;

public:
	State(sf::RenderWindow* window,  std::stack<State*>* states);
	virtual ~State();

	bool getQuit();
	void endStan();

	
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;

};

#endif

