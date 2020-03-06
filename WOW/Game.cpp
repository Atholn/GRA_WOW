#include "Game.h"
/// inicjalizacja zmiennych 
void Game::initVariables()
{
	this->window = NULL;
	this->fullscreen = false;
	this->dt = 0.f;
}

///inicjalizacja okna 
void Game::initWindow()
{
	std::ifstream ifs("Data/Config/window.txt");
	std::string title;
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();// granica okna
	unsigned framerate_limit = 120;  // czestotliwosc klatek 


	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
	}

	ifs.close();

	this-> window = new sf::RenderWindow(window_bounds, title,  sf::Style::Titlebar ); /// stworzenie nowego okna 
	this->window->setFramerateLimit(framerate_limit); // ilosc klatek
	
}

/// Pocz¹tek gry - inicjalizacja main menu 
void Game::initStates()
{
	this->states.push(new MainMenuState(this->window,  &this->states));
}

/// konstruktor 
Game::Game()
{
	this->initWindow();
	this->initStates();
	im.loadFromFile("Data/Images/Sprites/Player/icon.png");
	this->window->setIcon(170, 170, im.getPixelsPtr());
}
/// destruktor usuwanie kna
Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();	
	}
}
/// aktualizacja  czasu 
void Game::updateDt()
{
	this -> dt = this->dtClock.restart().asSeconds();
}
/// aktualizacja eventu 
void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent)) /// dawanie zdarzenia na okno 
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}

}

// aktualizacja  gry  update stanu gry ktory jest na górze stosu 
void Game::update()
{
	this->updateSFMLEvents();
	
	if (!this->states.empty()) 
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit()) /// sprawdz czy dany stan gry powinien sie zamknac  
		{
			this->states.top()->endStan();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->window->close();
	}
}
// rendowanie 

void Game::render()
{
	this->window->clear();

	if (!this->states.empty())
		this->states.top()->render(this->window);
	
	this->window->display(); /// pokazanie okna 
}
// uruchomienie gry
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();	
	}
}