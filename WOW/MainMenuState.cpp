#include "MainMenuState.h"
/// inicjalizacje funkcji


void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(static_cast<float>( this->window->getSize().x), static_cast<float>(this->window->getSize().y)));

	if (!this->backgroundTexture.loadFromFile("Data/Images/Backgrounds/bg1.png"))
	{
		throw"ERROR::MAINMANUSTATE::FAILED TO LOAD BACKGROUND TEXTURE";
	}
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts() /// inicjowanie czcionki
{
	if (!this->font.loadFromFile("Data/Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR : Could Not load Font");
	}
}

void MainMenuState::initButtons()
{


	Buttons.push_back(new Button(900, 500, 200, 50,
		&this->font, "Przeczytaj zanim zagrasz",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));

	Buttons[0]->update(1);
	Buttons.push_back(new Button(900, 600, 200, 50,
		&this->font, "Nowa Gra",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));

	Buttons.push_back(new Button(900, 700, 200, 50,
		&this->font, "Wznow Gre",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));

	Buttons.push_back( new Button(900, 800, 200, 50,
		&this->font, "Koniec Gry",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));



	/*this->buttons["INSTRUCTION"] = new Button(900, 500, 150, 50,
		&this->font, "Przeczytaj zanim zagrasz",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));


	this->buttons["GAME_STATE"] = new Button(900, 600, 150, 50,
		&this->font, "Nowa Gra",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["GAME_STATE_2"] = new Button(900, 700, 150, 50,
		&this->font, "Wznow Gre",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));



	this->buttons["EXIT_STATE"] = new Button(900, 800, 150, 50,
		&this->font, "Koniec Gry",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));*/
}



MainMenuState::MainMenuState(sf::RenderWindow* window,  std::stack<State*>* states)
	: State(window,  states)
{
	this->initBackground();
	this->initFonts();
	this->initButtons();

}

MainMenuState::~MainMenuState()
{
	auto it = this->Buttons.begin();

	for (it = this->Buttons.begin(); it != this->Buttons.end(); ++it)
	{
		delete *it;
	}
}



void MainMenuState::updateButtons()
{
	/// new game
	std::fstream ifs1("Data/Level/level.txt");

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	switch (int(cursor))
	{

	case 0: 
		this->states->push(new InstructionState(this->window, this->states, 1));
		break;

	case 1:
		
		if (ifs1.is_open())ifs1 << 1;
		ifs1.close();
		this->states->push(new LevelState(this->window, this->states));
		break;
	case 2:
		
		this->states->push(new LevelState(this->window, this->states));
		
		break;
	case 3: this->endStan(); break;
	

	default:
		break;
	}


}

void MainMenuState::updateInput(const float & dt)
{
	int  UpDo = 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		UpDo = 1;
		przesuniecie = true;
	}
	else
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			UpDo = 2;
			przesuniecie = true;
		}
		else UpDo = 3;




	if ((przesuniecie &&  time.asSeconds() >= 0.1f))
	{
		switch (UpDo)
		{
		case 1: moveUp(); przesuniecie = false; break;
		case 2: moveDown(); przesuniecie = false;  break;
		case 3: break;
		}

		clock.restart();
	}
}




void MainMenuState::moveUp()
{
	if (cursor - 1 >= 0)
	{

		Buttons[int(cursor)]->update(0);
		cursor-=1;
		
		std::cout << cursor << std::endl;
		Buttons[int(cursor)]->update(1);

	}

}

void MainMenuState::moveDown()
{
	if (cursor + 1 < Buttons.size())
	{

		Buttons[int(cursor)]->update(0);
		cursor += 1;

		Buttons[int(cursor)]->update(1);

	}
}



void MainMenuState::update(const float& dt)
{
	time = clock.getElapsedTime();
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget * target)
{
	for (auto &it : this->Buttons)
	{
		it->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);

}
