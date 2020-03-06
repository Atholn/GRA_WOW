
#include "MainMenuState.h"


class Game
{

private:

	sf::RenderWindow *window;  /// okno
	sf::Event sfEvent; // zdarzenie 
	bool fullscreen;
	sf::Image im;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states; /// stany gry
	
	void initVariables();
	void initWindow();
	void initStates();

public:


	Game();
	virtual ~Game();

	// aktualizowanie
	void updateDt();
	void updateSFMLEvents();
	void update();
	//rendowanie
	void render();
	// rdzen gry 
	void run();

};
