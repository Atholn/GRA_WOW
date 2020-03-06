
#ifndef LEVELSTATE_H
#define LEVELSTATE_H

#include "State.h"
#include "GameState.h"
#include "InstructionState.h"

class LevelState :
	public State
{
private:
	/// zmienne
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	sf::Font font;
	sf::View view;
	std::map<std::string, Button*>buttons;
	
	int lvl;
	int lvl_max;

	int k, l;
	std::vector <Button*> Buttons;
	sf::Clock clock;
	sf::Time time;

	float cursor = 0;
	bool przesuniecie = true;
	void moveUp();
	void moveDown();


	// funckje
	void initVariables();
	void initBackground();
	void initFonts();
	void initLevel();
	void initButtons();

public:
	LevelState(sf::RenderWindow* window,  std::stack<State*>* states);
	~LevelState();

	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = NULL);
	void render(sf::RenderTarget* target = NULL);
};

#endif