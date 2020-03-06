#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "InstructionState.h"
#include "LevelState.h"
class MainMenuState :
	public State
{
private:
	/// zmienne
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	sf::Font font;
	std::vector <Button*> Buttons;
	std::map<std::string, Button*>buttons;

	sf::Clock clock;
	sf::Time time;

	// funckje
	float cursor = 0;
	bool przesuniecie = true;


	void moveUp();
	void moveDown();

	void initBackground();
	void initFonts();
	void initButtons();

public:
	MainMenuState(sf::RenderWindow* window,  std::stack<State*>* states);
	virtual ~MainMenuState();

	void updateButtons();
	
	void renderButtons(sf::RenderTarget* target = NULL);
	void update(const float& dt);
	void updateInput(const float& dt);
	void render(sf::RenderTarget* target = NULL);
};

#endif