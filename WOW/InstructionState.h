#pragma once
#include "State.h"

class InstructionState :
	public State
{



	private:
		/// zmienne
		sf::Texture backgroundTexture;
		sf::RectangleShape background;
		sf::Text text;
		sf::Font font;

		int Stan = 0;
		///	Button* gamestate_btn;
		std::map<std::string, Button*>buttons;


		// funckje
		void initVariables();
		void initBackground();
		void initFonts();
		void initButtons();

	public:
		InstructionState(sf::RenderWindow* window,  std::stack<State*>* states, int stan);
		virtual ~InstructionState();
		

		/// functions
		//void endStan();
	//
		void updateInput(const float& dt);
		void updateButtons();
		void update(const float& dt);
		void renderButtons(sf::RenderTarget* target = NULL);
		void render(sf::RenderTarget* target = NULL);



};

