#include "State.h"
/// konstruktor
State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
	this->window = window;
	this->states = states;
	this->quit = false;
}

State::~State()
{

}

bool State::getQuit()
{
	return this->quit;
}

void State::endStan()
{
	this->quit = true;
}

