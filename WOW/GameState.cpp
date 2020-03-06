#include "GameState.h"

// inicjalizacja textur oraz czcionki
void GameState::initTextures()
{
	if(!this->textures["PLAYER_INDLE"].loadFromFile("Data/Images/Sprites/Player/Paladyn.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}

	if (!this->textures["ARROW"].loadFromFile("Data/Images/Sprites/Player/Arrow.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["ZOMBIE"].loadFromFile("Data/Images/Sprites/Player/Undeath.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["FIREBALL"].loadFromFile("Data/Images/Sprites/Player/Fireball.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["FIREBALLENEMY"].loadFromFile("Data/Images/Sprites/Player/FireballEnemy.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["COIN"].loadFromFile("Data/Images/Sprites/Player/Coin.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["WALL1"].loadFromFile("Data/Images/Sprites/Player/Wall1.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["WALL2"].loadFromFile("Data/Images/Sprites/Player/Wall2.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["WALL3"].loadFromFile("Data/Images/Sprites/Player/Wall3.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["WALL4"].loadFromFile("Data/Images/Sprites/Player/Wall4.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["DOOR"].loadFromFile("Data/Images/Sprites/Player/Door.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["DOOR_2"].loadFromFile("Data/Images/Sprites/Player/Door_2.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["BUM"].loadFromFile("Data/Images/Sprites/Player/BUM1.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	if (!this->textures["GOLD"].loadFromFile("Data/Images/Sprites/Player/Skarb.png"))
	{
		throw "ERROR::GAMESTATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE";
	}
	
	if (!this->font.loadFromFile("Data/Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR : Could Not load Font");
	}
	
}

// inicjalizacja gracza
void GameState::initPlayers()
{
	this->player = new Player(start_x, start_y, &this->textures["PLAYER_INDLE"]);
}

// inicjalizacja wrogow - Enemy
void GameState::initEnemy()
{
	
	EnemyArray = new std::vector<Enemy*>;  /// alokacja dynamiczna dla EnemyArray
	int x, y;
	bool pomoc;

	for (int i = 1; i < enemy_quantity; i++) /// Stworzenie  Armi stworów  o konkretnej liczbie ( enemy_quantity) przypadaj¹cej ka¿dy na inny level
	{
		x =   (generateRandom(x_max-2));
		y =   (generateRandom(y_max-2));
		
		pomoc = true;
		for ( int i=0; i<3;i++)
			for (int j = 0; j < 3; j++)
			{
				if (mapka[y - 1 + i][x - 1 + j] != 0 || ( abs(x - player->sprite->getPosition().x / 32) < 5 && abs(y - player->sprite->getPosition().y / 32) < 10)) pomoc = false;
			}


		if (pomoc)this->EnemyArray->push_back(new Enemy(32 * x, 32 * y, &this->textures["ZOMBIE"]));
				else i--;
	}

}

// inicjalizacja muru - rysowanie mapy
void GameState::initWall()
{
	WallArray = new std::vector<Wall*>;

	std::fstream ifs("Data/Level/level_"+std::to_string(this->lvl)+".txt");
	int pomoc;
	if (ifs.is_open())
	{
		counter = 0;
		ifs >> x_max >> y_max;
		for (int i = 0; i < y_max; i++)
		{
			mapka.push_back(std::vector<int>());
			for (int j = 0; j < x_max; j++) {
				ifs >> pomoc;
				
				switch (pomoc)
				{
				case 1:
					this->WallArray->push_back(new Wall(j * 32, i * 32, &this->textures["WALL" + std::to_string(this->lvl)]));
					mapka.back().push_back(counter);
					counter++;
					break;

				case 3: this->Start_door = new Wall(j * 32, i * 32, &this->textures["DOOR"]); start_x = j * 32; start_y = i * 32; mapka.back().push_back(0); break;
				case 4: this->End_door = new Wall(j * 32, i * 32, &this->textures["DOOR_2"]); mapka.back().push_back(0); break;
				case 5: this->Treasure = new Wall(j * 32, i * 32, &this->textures["GOLD"]);  mapka.back().push_back(0); break;
				case 0: mapka.back().push_back(0);  break;

				default: break;
				}
			}
		}
		ifs >> enemy_quantity;
	}

	for (int i = 0; i < x_max; i++)
	{
		this->WallArray->push_back(new Wall(i*32,-32, &this->textures["WALL" + std::to_string(this->lvl)]));
		this->WallArray->push_back(new Wall(i * 32, y_max * 32, &this->textures["WALL" + std::to_string(this->lvl)]));
	}

	for (int i = 0; i < y_max; i++)
	{
		this->WallArray->push_back(new Wall(-32, i * 32, &this->textures["WALL" + std::to_string(this->lvl)]));
		this->WallArray->push_back(new Wall(x_max * 32 , i * 32, &this->textures["WALL" + std::to_string(this->lvl)]));
	}

	ifs.close();
}

// inicjalizacja  i ustawienia textu 
void GameState::initText()
{
	CoinArray = new std::vector<Coin*>;
	Hajsy.setCharacterSize(25);
	Hajsy.setFillColor(sf::Color::Yellow);
	Hajsy.setFont(this->font);

	HP.setCharacterSize(25);
	HP.setFillColor(sf::Color::Red);
	HP.setFont(this->font);

	textDisplay.text.setPosition(50, 50);
	textDisplay.text.setCharacterSize(25);
	textDisplay.text.setFillColor(sf::Color::Red);
	textDisplay.text.setFont(this->font);

	End_text.setFillColor(sf::Color::White);
	End_text.setFont(this->font);
	End_text.setCharacterSize(50);
}

// inicjalizacja widoku
void GameState::initView()
{
	view.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	view.setCenter(sf::Vector2f(view.getSize().x / 2, view.getSize().y / 2));
	this->window->setView(view);
}

void GameState::initArrow()
{
	StartArrowArray = new std::vector<StartArrow*>;
	StartArrowArray->push_back(new StartArrow(player->sprite->getPosition().x-16, player->sprite->getPosition().y - 300, &this->textures["ARROW"]));
	StartArrowArray->push_back(new StartArrow(player->sprite->getPosition().x+48, player->sprite->getPosition().y + 300, &this->textures["ARROW"]));

	StartArrowArray->push_back(new StartArrow(player->sprite->getPosition().x - 300+32, player->sprite->getPosition().y+32, &this->textures["ARROW"]));
	StartArrowArray->push_back(new StartArrow(player->sprite->getPosition().x + 300, player->sprite->getPosition().y-32, &this->textures["ARROW"]));

	int licznik = 0;
	for (iterSA = StartArrowArray->begin(); iterSA != StartArrowArray->end(); iterSA++)
	{
		
		switch (licznik)
		{
		case 0:(*iterSA)->sprite->setRotation(0.f); (*iterSA)->setDirection(0); break;
		case 1:(*iterSA)->sprite->setRotation(180.f); (*iterSA)->setDirection(1); break;
		case 2:(*iterSA)->sprite->setRotation(270.f); (*iterSA)->setDirection(2); break;
		case 3:(*iterSA)->sprite->setRotation(90.f); (*iterSA)->setDirection(3); break;
		default:
			break;
		}
		licznik++;
	}

}

// konstruktor w ktorym sa odwolnia do inicjalizacji 
GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states,  int lvl)
	: State(window,  states)
{
	this->lvl = lvl;
	this->initTextures();
	this->initWall();
	this->initPlayers();
	this->initEnemy();
	this->initText();
	this->initView();
	this->initArrow();

	AttackArray = new std::vector<Attack*>;
	AttackEArray = new std::vector<Attack*>;
}

// destruktor w ktorym usuwamy wszystkie dynamiczne zmienne 
GameState::~GameState()
{
	delete this->player;
	delete this->End_door;
	delete this->Start_door;
	delete this->Treasure;

	for (iterSA = StartArrowArray->begin(); iterSA != StartArrowArray->end(); iterSA++)
	{
		delete *iterSA;
	}
	delete this->StartArrowArray;

	for (iterZ = EnemyArray->begin(); iterZ != EnemyArray->end(); iterZ++ )
	{	
			delete *iterZ;	
	}
	delete this->EnemyArray;

	for (iterA = AttackArray->begin(); iterA != AttackArray->end(); iterA++)
	{
			delete *iterA;
	}
	delete this->AttackArray;

	for (iterAE = AttackEArray->begin(); iterAE != AttackEArray->end(); iterAE++)
	{
			delete *iterAE;
	}
	delete this->AttackEArray;

	for (iterC= CoinArray->begin(); iterC != CoinArray->end(); iterC++)
	{
			delete *iterC;
	}
	delete this->CoinArray;

	for (iterW = WallArray->begin(); iterW != WallArray->end(); iterW++)
	{
			delete *iterW;
	}
	delete this->WallArray;
}

// aktualizacja przycioskow 
void GameState::updateInput(const float & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->player->update(dt);
		this->player->direction = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->player->update(dt);
		this->player->direction = 2;
	}
		
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->player->update(dt);
		this->player->direction = 3;
	}
		
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->player->update(dt);
		this->player->direction = 0;
	}
	else{}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->endStan();
	
	if (time1.asSeconds() >= 0.6f)
	{
		shoot = true;
	}

	if (shoot) 
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			shoot = false;
			clock1.restart();
			this->attack = new Attack(this->player->sprite->getPosition().x, this->player->sprite->getPosition().y, &this->textures["FIREBALL"]);
			this->attack->direction = this->player->direction;
			this->attack->AttackEnemy = false;
			this->attack->attackDamage = this->player->attackDamage;
			this->AttackArray->push_back(this->attack);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		this->player->movementSpeed += 100;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		this->player->movementSpeed -= 100;
	}


	/////WaLL  and player
	this->player->bX = this->player->sprite->getPosition().x;
	this->player->bY = this->player->sprite->getPosition().y;
	this->player->bD = this->player->direction;

	counter = 0;
	for (iterW = WallArray->begin(); iterW != WallArray->end(); iterW++)
	{

		if (this->player->sprite->getGlobalBounds().intersects((*WallArray)[counter]->sprite->getGlobalBounds(), rect))
		{
	
			if ((this->player->sprite->getPosition().x + 32 > (*WallArray)[counter]->sprite->getPosition().x || this->player->sprite->getPosition().x < (*WallArray)[counter]->sprite->getPosition().x + 32) 
				&& (this->player->direction == 1 || this->player->direction == 2))
			{
				if ((this->player->direction == this->player->bD) && this->player->direction == 1 && this->player->sprite->getPosition().x - rect.left == 0 )
				{///&& this->player->sprite->getPosition().x < this->player->bX
					this->player->canMoveLeft = false;
				//	this->player->canMoveUp = false;
					//this->player->canMoveDown = false;
					this->player->sprite->move(10, 0);
					std::cout << 1 << std::endl;
				}

				else if (this->player->direction == 2 && (this->player->direction == this->player->bD) && this->player->sprite->getPosition().x - rect.left<0 )
				{//&& this->player->sprite->getPosition().x> this->player->bX
					this->player->canMoveRight = false;
				//	this->player->canMoveUp = false;
				//	this->player->canMoveDown = false;
					this->player->sprite->move(-10, 0);
				}

				else {
						this->player->canMoveUp = false;
						this->player->canMoveDown = false;
						this->player->canMoveLeft = true;
						this->player->canMoveRight = true;

				}
			}
			else  if (this->player->sprite->getPosition().y < (*WallArray)[counter]->sprite->getPosition().y + 32 || this->player->sprite->getPosition().y + 32 >(*WallArray)[counter]->sprite->getPosition().y && (this->player->direction == 0 || this->player->direction == 3))
			{
					
					if (this->player->direction == 0 && (this->player->direction == this->player->bD) && this->player->sprite->getPosition().y - rect.top < 0)
						{// && this->player->sprite->getPosition().y> this->player->bY
							this->player->canMoveDown = false;
						//	this->player->canMoveLeft = false;
							//this->player->canMoveRight = false;
							this->player->sprite->move(0, -10);

						}
					else if (this->player->direction == 3 && (this->player->direction == this->player->bD) && this->player->sprite->getPosition().y - rect.top == 0 )
					{ //&& this->player->sprite->getPosition().y < this->player->bY
						this->player->canMoveUp = false;
						//this->player->canMoveLeft = false;
						//this->player->canMoveRight = false;
						this->player->sprite->move(0, 10);
					}
					else 
					{
						this->player->canMoveLeft = false;
						this->player->canMoveRight = false;
						this->player->canMoveUp = true;
						this->player->canMoveDown = true;
					}
			}
		}
		counter++;
	}
}

// aktualizacja wszystkiego 
void GameState::update(const float& dt)
{

	time1 = clock1.getElapsedTime();
	time2 = clock2.getElapsedTime();
	time3 = clock3.getElapsedTime();

	this->updateInput(dt);
	this->updateEnemy(dt);
	this->updateCoinBum(dt);
	this->updateAttack(dt);
	this->updateAttackE(dt);
	this->updateText(dt);
	this->updateView(dt);
	this->updateEnd(dt);
	this->updateArrow(dt);
}

// aktualizacja wrogow 
void GameState::updateEnemy(const float & dt)
{
	//// enemy update
	counter = 0;
	for (iterZ = EnemyArray->begin(); iterZ != EnemyArray->end(); iterZ++)
	{
		(*EnemyArray)[counter]->update(dt);
		counter++;
	}

	

	//// enemy and player
	if (time2.asSeconds() >= 0.5f)
	{
		clock2.restart();
		counter = 0;
		for (iterZ = EnemyArray->begin(); iterZ != EnemyArray->end(); iterZ++)
		{
			if (this->player->sprite->getGlobalBounds().intersects((*EnemyArray)[counter]->sprite->getGlobalBounds()))
			{
				textDisplay.text.setString(std::to_string((*EnemyArray)[counter]->attackDamage));
				textDisplay.text.setPosition(player->sprite->getPosition().x, player->sprite->getPosition().y);
				TextDisplayArray.push_back(textDisplay);
				this->player->hp -= (*EnemyArray)[counter]->attackDamage;
			
			}
			counter++;
		}
	}

	////enemy and wall 
	int x, y;
	bool pomoc;
	counter = 0;
	for (iterZ = EnemyArray->begin(); iterZ != EnemyArray->end(); iterZ++)
	{
		x = int(((*EnemyArray)[counter]->sprite->getPosition().x / 32));
		y = int(((*EnemyArray)[counter]->sprite->getPosition().y / 32));
		
		int TT[3][3] = {};
		pomoc = false;
		if (x  >= 1 && y >= 1 && x<x_max-1 && y<y_max-1)
		{			
			for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (mapka[ y+i-1  ][x+j-1 ] != 0) 
				{ 			
					pomoc = true; 
					TT[i][j] = mapka[y + i - 1][x + j - 1];
				}			
			}
			if (pomoc==true)
			{
				for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)
				{
					if ((*EnemyArray)[counter]->sprite->getGlobalBounds().intersects((*WallArray)[TT[i][j]]->sprite->getGlobalBounds()))
						switch ((*EnemyArray)[counter]->direction)
						{
						case 0:
							(*EnemyArray)[counter]->canMoveDown = false;
							(*EnemyArray)[counter]->sprite->move(0, -3);
							(*EnemyArray)[counter]->direction = 3;
							break;
						case 1:
							(*EnemyArray)[counter]->canMoveLeft = false;
							(*EnemyArray)[counter]->sprite->move(3, 0);
							(*EnemyArray)[counter]->direction = 2;
							break;
						case 2:
							(*EnemyArray)[counter]->canMoveRight = false;
							(*EnemyArray)[counter]->sprite->move(-3, 0);
							(*EnemyArray)[counter]->direction = 1;
							break;
						case 3:
							(*EnemyArray)[counter]->canMoveUp = false;
							(*EnemyArray)[counter]->sprite->move(0, 3);
							(*EnemyArray)[counter]->direction = 0;
							break;
						default:
							break;
						}
				///	(*EnemyArray)[counter]->counterWalking = 0;
				}
			}		
		}
		counter++;
	}

	// wrogowie  wraz z systemem wykrywania gracza - inicjalizcja atakow 
	counter = 0;
	for (iterZ = EnemyArray->begin(); iterZ != EnemyArray->end(); iterZ++)
	{
		
		if (((*EnemyArray)[counter]->direction == 1 || (*EnemyArray)[counter]->direction == 2 || (*EnemyArray)[counter]->direction == 3)
			&& (*EnemyArray)[counter]->sprite->getPosition().y - player->sprite->getPosition().y < 0.f &&abs((*EnemyArray)[counter]->sprite->getPosition().x - player->sprite->getPosition().x) < 30.f)
		{
			(*EnemyArray)[counter]->blokada = false;
			(*EnemyArray)[counter]->direction = 0;
			(*EnemyArray)[counter]->sprite->setTextureRect(sf::IntRect(0 * 32, 32 * 0, 32, 32));
		}
		else if (((*EnemyArray)[counter]->direction == 1 || (*EnemyArray)[counter]->direction == 2 || (*EnemyArray)[counter]->direction == 0)
			&& (*EnemyArray)[counter]->sprite->getPosition().y - player->sprite->getPosition().y > 0.f &&abs((*EnemyArray)[counter]->sprite->getPosition().x - player->sprite->getPosition().x) < 30.f)
		{
			(*EnemyArray)[counter]->blokada = false;
			(*EnemyArray)[counter]->direction = 3;
			(*EnemyArray)[counter]->sprite->setTextureRect(sf::IntRect(0 * 32, 32 * 3, 32, 32));
		}
		else if (((*EnemyArray)[counter]->direction == 2 || (*EnemyArray)[counter]->direction == 3 || (*EnemyArray)[counter]->direction == 0)
			&& (*EnemyArray)[counter]->sprite->getPosition().x - player->sprite->getPosition().x > 0.f &&abs((*EnemyArray)[counter]->sprite->getPosition().y - player->sprite->getPosition().y) < 30.f)
		{
			(*EnemyArray)[counter]->blokada = false;
			(*EnemyArray)[counter]->direction = 1;
			(*EnemyArray)[counter]->sprite->setTextureRect(sf::IntRect(0 * 32, 32 * 1, 32, 32));
		}
		else if (((*EnemyArray)[counter]->direction == 1 || (*EnemyArray)[counter]->direction == 3 || (*EnemyArray)[counter]->direction == 0)
			&& (*EnemyArray)[counter]->sprite->getPosition().x - player->sprite->getPosition().x < 0.f && abs((*EnemyArray)[counter]->sprite->getPosition().y - player->sprite->getPosition().y) < 30.f)
		{
			(*EnemyArray)[counter]->blokada = false;
			(*EnemyArray)[counter]->direction = 2;
			(*EnemyArray)[counter]->sprite->setTextureRect(sf::IntRect(0 * 32, 32 * 2, 32, 32));
		}
		else (*EnemyArray)[counter]->blokada = true;


		(*EnemyArray)[counter]->counterWalking=0;
		if (time3.asSeconds() >= 1.0f)
		{
			clock3.restart();
			
			if (((abs((*EnemyArray)[counter]->sprite->getPosition().x - player->sprite->getPosition().x) <500.f&& abs((*EnemyArray)[counter]->sprite->getPosition().y - player->sprite->getPosition().y) < 80.f)|| 
				(abs((*EnemyArray)[counter]->sprite->getPosition().x - player->sprite->getPosition().x) < 80.f && abs((*EnemyArray)[counter]->sprite->getPosition().y - player->sprite->getPosition().y) <500.f))
				&& (abs ((*EnemyArray)[counter]->sprite->getPosition().x - player->sprite->getPosition().x) < 80.f || abs((*EnemyArray)[counter]->sprite->getPosition().y - player->sprite->getPosition().y) < 80.f))
			{
				if ((*EnemyArray)[counter]->canMoveDown && (*EnemyArray)[counter]->canMoveUp && (*EnemyArray)[counter]->canMoveLeft && (*EnemyArray)[counter]->canMoveRight)
				{

					switch ((*EnemyArray)[counter]->direction)
					{
					case 0:this->attack = new Attack((*EnemyArray)[counter]->sprite->getPosition().x, (*EnemyArray)[counter]->sprite->getPosition().y - 32.f, &this->textures["FIREBALLENEMY"]); break;
					case 1:this->attack = new Attack((*EnemyArray)[counter]->sprite->getPosition().x + 32.f, (*EnemyArray)[counter]->sprite->getPosition().y, &this->textures["FIREBALLENEMY"]); break;
					case 2:this->attack = new Attack((*EnemyArray)[counter]->sprite->getPosition().x - 32.f, (*EnemyArray)[counter]->sprite->getPosition().y, &this->textures["FIREBALLENEMY"]); break;
					case 3:this->attack = new Attack((*EnemyArray)[counter]->sprite->getPosition().x, (*EnemyArray)[counter]->sprite->getPosition().y + 32.f, &this->textures["FIREBALLENEMY"]); break;
					}

					this->attack->AttackEnemy = true;
					this->attack->direction = (*EnemyArray)[counter]->direction;
					this->AttackEArray->push_back(this->attack); 	
				}
			}
			counter++;
		}
	}

	// delete enemy
	for (iterZ = EnemyArray->begin(); iterZ != EnemyArray->end(); )
	{
		if ((*iterZ)->alive == false)
		{
			if (generateRandom(3) == 1)
			{
				this->coin = new Coin((*iterZ)->sprite->getPosition().x, (*iterZ)->sprite->getPosition().y, &this->textures["COIN"]);
				this->coin->isCoin = true;
				this->CoinArray->push_back(this->coin);
			}

			delete *iterZ;
			EnemyArray->erase(iterZ);
			break;
		}
		else
		{
			iterZ++;
		}

	}
}

//aktualizacja Coin "hajsy" oraz wybuchy
void GameState::updateCoinBum(const float & dt)
{
	//// Coin 
	counter = 0;
	for (iterC = CoinArray->begin(); iterC != CoinArray->end(); iterC++)
	{
		if (this->player->sprite->getGlobalBounds().intersects((*CoinArray)[counter]->sprite->getGlobalBounds()))
		{
			if ((*CoinArray)[counter]->isCoin == true)
			{
				this->player->coins += 10;

			}
			(*CoinArray)[counter]->destroy = true;
		}
		counter++;
	}

	//// Coin delete
	for (iterC = CoinArray->begin(); iterC != CoinArray->end(); )
	{
		if ((*iterC)->destroy)
		{
			delete *iterC;
			CoinArray->erase(iterC);
			break;
		}
		else
		{
			iterC++;
		}

	}

	////  update BUM 
	counter = 0;
	for (iterC = CoinArray->begin(); iterC != CoinArray->end(); iterC++)
	{
		if ((*CoinArray)[counter]->isCoin== false)
		{
			(*CoinArray)[counter]->update(dt);
		}
		counter++;
	}

}

// akutalizacja ataku gracza 
void GameState::updateAttack(const float & dt)
{
	// zderzenie ataku gracza oraz ataku wroga
	counter = 0;
	for (iterA = AttackArray->begin(); iterA != AttackArray->end(); iterA++)
	{
		counter2 = 0;
		for (iterAE = AttackEArray->begin(); iterAE != AttackEArray->end(); iterAE++)
		{
				if (((*AttackArray)[counter]->direction == 1 && (*AttackEArray)[counter2]->direction == 2) || ((*AttackArray)[counter]->direction == 2 && (*AttackEArray)[counter2]->direction == 1) ||
				((*AttackArray)[counter]->direction == 0 && (*AttackEArray)[counter2]->direction == 3) || ((*AttackArray)[counter]->direction == 3 && (*AttackEArray)[counter2]->direction == 0))
				{
					if (abs((*AttackArray)[counter]->sprite->getPosition().x - (*AttackEArray)[counter2]->sprite->getPosition().x) < 50.f && abs((*AttackArray)[counter]->sprite->getPosition().y - (*AttackEArray)[counter2]->sprite->getPosition().y) < 50.f)

					{
						this->bum = new Coin((*AttackArray)[counter]->sprite->getPosition().x-11, (*AttackArray)[counter]->sprite->getPosition().y-11, &this->textures["BUM"]);
					
						this->bum->direction = this->player->direction;
						this->bum->isCoin = false;
						this->CoinArray->push_back(this->bum);

						(*AttackArray)[counter]->destroy = true;
						(*AttackEArray)[counter2]->destroy = true;
					}
				}
			counter2++;
		}
		counter++;
	}


		// attak oraz mur
	int x, y;
	bool pomoc;
	counter = 0;
	for (iterA = AttackArray->begin(); iterA != AttackArray->end(); iterA++)
	{
		x = int((*AttackArray)[counter]->sprite->getPosition().x / 32);
		y = int((*AttackArray)[counter]->sprite->getPosition().y / 32);

		int TT[3][3] = {};
		if (x >= 1 && y >= 1 && x < x_max - 1 && y < y_max - 1)
		{

			pomoc = false;

			for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)
			{
				if (mapka[y + i - 1][x + j - 1] != 0)
				{
					pomoc = true;

					TT[i][j] = mapka[y + i - 1][x + j - 1];
				}

			}

			if (pomoc == true)
			{
				for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)
				{
					if ((*AttackArray)[counter]->sprite->getGlobalBounds().intersects((*WallArray)[TT[i][j]]->sprite->getGlobalBounds()))
						(*AttackArray)[counter]->destroy = true;

				}
			}
		}
		counter++;
	}

	// usuwanie ataku 

	for (iterA = AttackArray->begin(); iterA != AttackArray->end(); )
	{
		if ((*iterA)->destroy) {
			delete *iterA;
			iterA = this->AttackArray->erase(iterA);
		}
		else {
			iterA++;
		}
	}


	// atak oraz jednostki
	counter = 0;
	for (iterA = AttackArray->begin(); iterA != AttackArray->end(); iterA++)
	{
		counter2 = 0;
		for (iterZ = EnemyArray->begin(); iterZ != EnemyArray->end(); iterZ++)
		{
			if ((*AttackArray)[counter]->sprite->getGlobalBounds().intersects((*EnemyArray)[counter2]->sprite->getGlobalBounds()))
			{
				(*AttackArray)[counter]->destroy = true;
				textDisplay.text.setString(std::to_string((*AttackArray)[counter]->attackDamage));
				textDisplay.text.setPosition((*EnemyArray)[counter2]->sprite->getPosition().x, (*EnemyArray)[counter2]->sprite->getPosition().y);
				TextDisplayArray.push_back(textDisplay);

				(*EnemyArray)[counter2]->hp -= (*AttackArray)[counter]->attackDamage;
				if ((*EnemyArray)[counter2]->hp <= 0)
				{
					(*EnemyArray)[counter2]->alive = false;
				}	
			}

			counter2++;
		}
		counter++;
	}

	

	// akutalizacja 
	counter = 0;
	for (iterA = AttackArray->begin(); iterA != AttackArray->end(); iterA++)
	{
		(*AttackArray)[counter]->update(dt);
		counter++;
	}


	

}

// akutalizacja ataku wroga
void GameState::updateAttackE(const float & dt)
{

	// kolizja ataku wraz murem 
	int x, y;
	bool pomoc;
	counter = 0;
	for (iterAE = AttackEArray->begin(); iterAE != AttackEArray->end(); iterAE++)
	{
		x = int((*AttackEArray)[counter]->sprite->getPosition().x / 32);
		y = int((*AttackEArray)[counter]->sprite->getPosition().y / 32);

		int TT[3][3] = {};
		if (x >= 1 && y >= 1 && x < x_max - 1 && y < y_max - 1)
		{
			pomoc = false;

			for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)
			{
				if (mapka[y + i - 1][x + j - 1] != 0)
				{
					pomoc = true;
					
					TT[i][j] = mapka[y + i - 1][x + j - 1];
				}
			}
			if (pomoc == true)
			{
				for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)
				{
					if (TT[i][j] != -1) if ((*AttackEArray)[counter]->sprite->getGlobalBounds().intersects((*WallArray)[TT[i][j]]->sprite->getGlobalBounds()))
					{
						(*AttackEArray)[counter]->destroy = true; break;
					}
				}
			}
		}
		counter++;
	}
	// usuwanie ataku 
	for (iterAE = AttackEArray->begin(); iterAE != AttackEArray->end(); )
	{
		if ((*iterAE)->destroy) 
		{
			delete *iterAE;
			iterAE = this->AttackEArray->erase(iterAE);
		}
		else 
		{
			iterAE++;
		}

	}


	// kolizja ataku wroga z graczem 
	counter = 0;
	for (iterAE = AttackEArray->begin(); iterAE != AttackEArray->end(); iterAE++)
	{
		counter2 = 0;
		for (iterZ = EnemyArray->begin(); iterZ != EnemyArray->end(); iterZ++)
		{
		 if ( (*AttackEArray)[counter]->sprite->getGlobalBounds().intersects(this->player->sprite->getGlobalBounds()))
			{
				(*AttackEArray)[counter]->destroy = true;
				textDisplay.text.setString(std::to_string((*EnemyArray)[counter2]->attackDamage ));
				textDisplay.text.setPosition(player->sprite->getPosition().x, player->sprite->getPosition().y);
				TextDisplayArray.push_back(textDisplay);

				this->player->hp = this->player->hp - (*EnemyArray)[counter]->attackDamage;

				break;
			}
			counter2++;
		}
		counter++;
	}



	///aktualizacja ataku
	counter = 0;
	for (iterAE = AttackEArray->begin(); iterAE != AttackEArray->end(); iterAE++)
	{
		(*AttackEArray)[counter]->update(dt);
		counter++;
	}
	// usuwanie ataku 
	for (iterAE = AttackEArray->begin(); iterAE != AttackEArray->end(); )
	{
		if ((*iterAE)->destroy)
		{
			delete *iterAE;
			iterAE = this->AttackEArray->erase(iterAE);
		}
		else
		{
			iterAE++;
		}

	}

}

//aktualizacja tekstu - obrazenia 
void GameState::updateText(const float & dt)
{
	counter = 0;
	for (iterT = TextDisplayArray.begin(); iterT != TextDisplayArray.end(); iterT++)
	{
		if (TextDisplayArray[counter].destroy == true) 
		{
			TextDisplayArray.erase(iterT); 
			break; 
		}
		counter++;
	}
}

//aktualizacja widoku 
void GameState::updateView(const float & dt)
{
	if (this->player->sprite->getPosition().x < 32 * 0 + viewControl * 1.7 && this->player->sprite->getPosition().y < 32 * 0 + viewControl)
	{
		xy = 1; //<^
	} 
	else if (this->player->sprite->getPosition().x < 32 * 0 + viewControl * 1.7  && this->player->sprite->getPosition().y > 32 * 0 + viewControl 
		&& this->player->sprite->getPosition().y < 32 * y_max - viewControl)
	{
		xy = 2; // <
	} 
	else if (this->player->sprite->getPosition().x < 32 * 0 + viewControl * 1.7 && this->player->sprite->getPosition().y > 32 * y_max - viewControl)
	{
		xy = 3;// <v
	}
	else if (this->player->sprite->getPosition().x > 32 * 0 + viewControl * 1.7 && this->player->sprite->getPosition().x < 32 * x_max - viewControl * 1.7 
		&& this->player->sprite->getPosition().y > 32 * y_max - viewControl)
	{
		xy = 4; //v
	} 
	else if (this->player->sprite->getPosition().x > 32 * x_max - viewControl * 1.7 && this->player->sprite->getPosition().y > 32 * y_max - viewControl)
	{
		xy = 5; 
	}
	else if (this->player->sprite->getPosition().x > 32 * x_max - viewControl * 1.7 && this->player->sprite->getPosition().y > 32 * 0 + viewControl 
		&& this->player->sprite->getPosition().y < 32 * y_max - viewControl)
	{
		xy = 6; // >
	}
	else if (this->player->sprite->getPosition().x > 32 * x_max - viewControl * 1.7  && this->player->sprite->getPosition().y < 32 * 0 + viewControl)
	{
		xy = 7;// ^>
	}
	else if (this->player->sprite->getPosition().x > 32 * 0 + viewControl * 1.7 && this->player->sprite->getPosition().x < 32 * x_max - viewControl * 1.7
		&& this->player->sprite->getPosition().y < 32 * 0 + viewControl)
	{
		xy = 8; // ^
	}
	else { xy = 0; }

	switch (xy)
	{
	case 1:	view.setCenter(viewControl*1.7, viewControl); break; // <^
	case 2:	view.setCenter(viewControl*1.7, this->player->sprite->getPosition().y); break;// <
	case 3:	view.setCenter(viewControl*1.7, y_max * 32 - viewControl); break;// <v
	case 4:	view.setCenter(this->player->sprite->getPosition().x, y_max * 32 - viewControl); break;// v
	case 5:	view.setCenter(x_max * 32 - viewControl*1.7, y_max * 32 - viewControl); break;// v>
	case 6:	view.setCenter(x_max * 32 - viewControl * 1.7, this->player->sprite->getPosition().y); break;// >
	case 7:	view.setCenter(x_max * 32 - viewControl * 1.7, viewControl); break;// ^>
	case 8:	view.setCenter(this->player->sprite->getPosition().x, viewControl); break;// ^
	case 0:	view.setCenter(this->player->sprite->getPosition().x, this->player->sprite->getPosition().y); break;// 
	}

	Hajsy.setPosition(view.getCenter().x - window->getSize().x / 2, view.getCenter().y - window->getSize().y / 2);
	HP.setPosition(view.getCenter().x - window->getSize().x / 2, view.getCenter().y - window->getSize().y / 2 + 30);

}

//aktualizacja dzialaia zwiazanego z zakonczeniem levela
void GameState::updateEnd(const float & dt)
{
	if (this->player->sprite->getGlobalBounds().intersects(End_door->sprite->getGlobalBounds()) && ifTreasure == true)
	{

		if (this->lvl != this->lvl_max)
		{
			std::fstream ifs1("Data/Level/level.txt");
			if (ifs1.is_open())
			{
				ifs1 << this->lvl + 1;
			}
			ifs1.close();
			this->endStan();
		}
		else
		{
			this->player->canMoveUp = false;
			this->player->canMoveDown = false;
			this->player->canMoveLeft = false;
			this->player->canMoveRight = false;

			End_text.setPosition(this->player->sprite->getPosition().x - 200, this->player->sprite->getPosition().y - 200);

			End_text.setString("Koniec gry! \n zdobyles " + std::to_string(this->player->coins) + " coins\n Kliknij SPACE by powrocic do menu ");

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))this->endStan();
		}
	}

	if (this->player->sprite->getGlobalBounds().intersects(Treasure->sprite->getGlobalBounds()))
	{
		if (!ifTreasure)
		{
			textDisplay.text.setString("Odnaleziono Skarb!");
			textDisplay.text.setPosition(this->player->sprite->getPosition().x, this->player->sprite->getPosition().y);
			TextDisplayArray.push_back(textDisplay);
			this->Treasure->sprite->setTextureRect(sf::IntRect(0, 33, 32, 32));
			ifTreasure = true;
		}
	}
	if (this->player->hp <= 0) {

		this->player->canMoveUp = false;
		this->player->canMoveDown = false;
		this->player->canMoveLeft = false;
		this->player->canMoveRight = false;

		End_text.setPosition(this->player->sprite->getPosition().x - 200, this->player->sprite->getPosition().y - 200);

		End_text.setString("Koniec gry! \n zdobyles " + std::to_string(this->player->coins) + " coins\n Kliknij SPACE by powrocic do menu ");

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))this->endStan();
	}
}

// aktualizacja strza³ek 
void GameState::updateArrow(const float & dt)
{
	iterSA = StartArrowArray->begin();
	if ((*iterSA)->destroy == false)
	{
		for (iterSA = StartArrowArray->begin(); iterSA != StartArrowArray->end(); iterSA++)
		{
			(*iterSA)->update(dt);
		}

		iterSA = StartArrowArray->begin();
		if ((*iterSA )->sprite->getGlobalBounds().intersects(Start_door->sprite->getGlobalBounds())) { (*iterSA)->destroy = true; }
	}



}

//rendowanie  
void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

		if (this->player->hp  <= 0 || (this->player->sprite->getGlobalBounds().intersects(End_door->sprite->getGlobalBounds()) && ifTreasure == true && this->lvl == this->lvl_max))
		{
			this->window->draw(this->End_text);	
		}
		else
		{
			counter = 0;
			for (iterA = AttackArray->begin(); iterA != AttackArray->end(); iterA++)
			{
				(*AttackArray)[counter]->render(target);
				counter++;
			}
			
			counter = 0;
			for (iterAE = AttackEArray->begin(); iterAE != AttackEArray->end(); iterAE++)
			{
				(*AttackEArray)[counter]->render(target);
				counter++;
			}

			counter = 0;
			for (iterC = CoinArray->begin(); iterC != CoinArray->end(); iterC++)
			{
				(*CoinArray)[counter]->render(target);
				counter++;
			}
			counter = 0;
			for (iterW = WallArray->begin(); iterW != WallArray->end(); iterW++)
			{
				(*WallArray)[counter]->render(target);
				counter++;
			}
			
			End_door->render(target);
			Start_door->render(target);
			Treasure->render(target);


			iterSA = StartArrowArray->begin();
			if ((*iterSA)->destroy == false)
			for (iterSA = StartArrowArray->begin(); iterSA != StartArrowArray->end(); iterSA++)
			{
				(*iterSA)->render(target);
			}



			counter = 0;
			for (iterZ = EnemyArray->begin(); iterZ != EnemyArray->end(); iterZ++)
			{
				(*EnemyArray)[counter]->render(target);
				counter++;
			}

			counter = 0;
			for (iterT = TextDisplayArray.begin(); iterT != TextDisplayArray.end(); iterT++)
			{
				TextDisplayArray[counter].update();
				this->window->draw(TextDisplayArray[counter].text);
				counter++;
			}

			this->window->setView(view);
			Hajsy.setString("Hajsy: " + std::to_string(player->coins));
			HP.setString("HP: " + std::to_string(player->hp));
			this->window->draw(Hajsy);
			this->window->draw(HP);
			
			this->player->render(target);
		}
		
}
