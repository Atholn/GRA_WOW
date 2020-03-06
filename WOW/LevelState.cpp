#include "LevelState.h"
#include "GameState.h"
#include "InstructionState.h"
#include "LevelState.h"
#include "MainMenuState.h"
/// inicjalizacje funkcji

void LevelState::initVariables()
{
}

void LevelState::initBackground()
{

}

void LevelState::initFonts() /// inicjowanie czcionki
{
	if (!this->font.loadFromFile("Data/Fonts/Dosis-Light.ttf"))
	{
		throw ("ERROR : Could Not load Font");
	}
}

void LevelState::initLevel()
{
		std::fstream ifs1("Data/Level/level.txt");
		if (ifs1.is_open())
		{
			ifs1 >> this->lvl >> this->lvl_max;
		}
		ifs1.close();

}

void LevelState::initButtons()
{


	for (int i = 0; i <= this->lvl_max-1; i++)
	{
		Buttons.push_back(new Button(900, (i+1) * 100, 150, 50,
			&this->font, std::to_string(i+1),
			sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));

		if (i != 0)
		{
			Buttons[i]->Block= true;
		}else Buttons[0]->update(1);


	}

}

LevelState::LevelState(sf::RenderWindow* window,  std::stack<State*>* states)
	: State(window,  states)
{

	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initLevel();
	this->initButtons();
	view.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

	view.setCenter(sf::Vector2f(window->getSize().x - 960, window->getSize().y - 540));

}

LevelState::~LevelState()
{
	auto it = this->Buttons.begin();

	for (it = this->Buttons.begin(); it != this->Buttons.end(); ++it)
	{
		delete *it;
	}
}

void LevelState::updateInput(const float & dt)
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


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->endStan();
}

void LevelState::updateButtons()
{
	std::fstream ifs1("Data/Level/level.txt");
	
	if (ifs1.is_open())
	{
		ifs1 >> k >> l;
		
	}
	ifs1.close();
	if (k <= l) for (int i = 1; i <= k; i++)this->Buttons[i-1]->Block = false;


	for (int i = 0; i <= this->l-1; i++)
	{
		if (i  != cursor)Buttons[i]->update(0);
		else Buttons[i]->update(1);
		
	}


		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&&time.asSeconds() >= 0.1f) )
		{	
			this->states->push(new GameState(this->window, this->states,cursor+1));
			if ( cursor + 1 ==1) this->states->push(new InstructionState(this->window,  this->states, 2));
			clock.restart();
		}
	
}

void LevelState::moveUp()
{
	if (cursor -1 >= 0)
	{
		Buttons[int(cursor)]->update(0);
		cursor -= 1;

		Buttons[int(cursor)]->update(1);
	
	}

}

void LevelState::moveDown()
{

	if (cursor< k-1)
	{

		Buttons[int(cursor)]->update(0);
		cursor += 1;

		Buttons[int(cursor)]->update(1);


	}
}
void LevelState::update(const float& dt)
{
	time = clock.getElapsedTime();

	this->updateInput(dt);
	this->updateButtons();

	window->setView(view);
}


void LevelState::renderButtons(sf::RenderTarget * target)
{
	for (auto &it : this->Buttons)
	{
		it->render(target);
	}
}

void LevelState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->renderButtons(target);

}
