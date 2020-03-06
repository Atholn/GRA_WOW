#include "InstructionState.h"



void InstructionState::initBackground()
{
	//this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));
	/////this->background.setSize(sf::Vector2f(1920,1080));

	//if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png"))
	//{
	//	throw"ERROR::MAINMANUSTATE::FAILED TO LOAD BACKGROUND TEXTURE";
	//}

	//this->background.setTexture(&this->backgroundTexture);
}

void InstructionState::initFonts() /// inicjowanie czcionki
{
	if (!this->font.loadFromFile("Data/Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR : Could Not load Font");
	}
}



void InstructionState::initVariables()
{
}

void InstructionState::initButtons()
{
}



InstructionState::InstructionState(sf::RenderWindow* window,  std::stack<State*>* states,int stan)
	: State(window,  states)
{
	this->Stan = stan;
	this->initVariables();
	this->initBackground();
	this->initFonts();

	this->initButtons();


	text.setPosition(this->window->getSize().x/2-400, this->window->getSize().y / 2-400);
	text.setFillColor(sf::Color::White);
	text.setFont(this->font);
	text.setCharacterSize(30);

	

	switch (this->Stan)
	{
	case 1:	text.setString("Witaj w grze WOW! \n\n Opcje gry:\n\n Wyjscie z danego stanu gry : ESC\n\n Ruch w gore : ^\n\n  Ruch w dol : v\n\n  Ruch w lewo : >\n\n  Ruch w prawo : <\n\n  Strzal : SPACE");
		break;
	case 2:	text.setString("Zabij Zombie stojace Ci na drodze oraz zdobadz Zloty Skarb\n\n Jezeli tego dokonasz odnajdz zlote drzwi i udaj sie do nich aby odblokowac nastepny poziom\n\nAby rozpoczac gre nacisnij SPACE\nAby wyjsc do menu nacisnij ESC\n");
		break;
	
	default: break;
	}

}

InstructionState::~InstructionState()
{
}



void InstructionState::updateInput(const float & dt)
{


}

void InstructionState::updateButtons()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		this->endStan();
	
	if (Stan!= 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{	
		this->endStan();
	}


}

void InstructionState::update(const float& dt)
{

	this->updateInput(dt);

	this->updateButtons();
	sf::View view;
	view.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

	view.setCenter(sf::Vector2f(window->getSize().x - 960, window->getSize().y - 540));
	window->setView(view);

}

void InstructionState::renderButtons(sf::RenderTarget * target)
{


}

void InstructionState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->text);

	this->renderButtons(target);

}
