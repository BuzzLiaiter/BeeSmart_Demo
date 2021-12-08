#include "Game.h"
#include "TheBee.h"


void Game::initVariables()
{
	this->window = NULL;
	this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode.height = 945;
	this->videoMode.width = 1000;
	this->window = new sf::RenderWindow(this->videoMode, "BeeSmart", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initBee()
{
	this->bee = new TheBee();
}

//objects
void Game::initFlower()
{
	this->flow1 = new Flower();
}

void Game::initFlower2()
{
	this->flow2 = new Flower();
	this->flow2->changePosition(270, 470);
}


void Game::initHive()
{
	this->hive = new Hive(); 
}
void Game::initTextStart()
{
	if (!this->start.loadFromFile("Fonts/PixelFont.ttf"))
	{
		std::cout << "ERROR fontStart";
	}
	this->startText.setFont(this->font);
	this->startText.setCharacterSize(50);
	this->startText.setFillColor(sf::Color::Yellow);
	this->startText.setOutlineColor(sf::Color::Red);
	this->startText.setOutlineThickness(5);
	this->startText.setString("HELP THE BEE GET TO THE HIVE");
	this->startText.setLetterSpacing(5);
	this->startText.setPosition(
		this->window->getSize().x / 2.f - this->startText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->startText.getGlobalBounds().height / 2.f
	);
	this->startText2.setFont(this->font);
	this->startText2.setCharacterSize(50);
	this->startText2.setFillColor(sf::Color::Yellow);
	this->startText2.setOutlineColor(sf::Color::Red);
	this->startText2.setOutlineThickness(5);
	this->startText2.setString("AND COLLECT TWO FLOWERS");
	this->startText2.setLetterSpacing(5);
	this->startText2.setPosition(
		this->window->getSize().x / 2.f - this->startText2.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->startText2.getGlobalBounds().height / 2.f + 50
	);
}

void Game::initGameOvText()
{
	if (!this->font.loadFromFile("Fonts/PixelFont.ttf"))
	{
		std::cout << "ERROR font";
	}
		this->mainText.setFont(this->font);
		this->mainText.setCharacterSize(100);
		this->mainText.setFillColor(sf::Color::Yellow);
		this->mainText.setOutlineColor(sf::Color::Red);
		this->mainText.setOutlineThickness(5);
		this->mainText.setString("Bee at Home");
		this->mainText.setLetterSpacing(5);
		this->mainText.setPosition(
			this->window->getSize().x / 2.f - this->mainText.getGlobalBounds().width / 2.f, 
			this->window->getSize().y / 2.f - this->mainText.getGlobalBounds().height / 2.f
		);

		this->pointsText.setFont(this->font);
		this->pointsText.setCharacterSize(50);
		this->pointsText.setFillColor(sf::Color::Red);
		this->pointsText.setOutlineColor(sf::Color::Yellow);
		this->pointsText.setOutlineThickness(5);
		this->pointsText.setLetterSpacing(3);
		this->pointsText.setString("Press REPLAY or EXIT");
		this->pointsText.setPosition(210,550);

		this->madeBy.setFont(this->font);
		this->madeBy.setCharacterSize(20);
		this->madeBy.setFillColor(sf::Color::Black);
		this->madeBy.setLetterSpacing(2);
		this->madeBy.setString("Felenko Svitlana and Liaiter Mykhailo");
		this->madeBy.setPosition(230, 600);

}
//Constructors/destructors
Game::Game()
{
	this->score = 0;
	this->number = 0;
	this->numberY = 0;
	this->isStart = true;
	action = 0;
	this->initMenu();
	this->initVariables();
	this->initWindow();
	this->initTexturesLeft();
	this->initSpriteLeft();
	this->initTexturesRight();
	this->initSpriteRight();
	this->initTexturesBack();
	this->initSpriteBack();
	this->initTexturesForward();
	this->initSpriteForward();
	this->initTexturesPlay();
	this->initSpritePlay();
	this->initTexturesPickup();
	this->initSpritePickup();
	this->initTexturesExit();
	this->initSpriteExit();
	this->initTexturesRestart();
	this->initSpriteRestart();
	this->initFlower();
	this->initFlower2();
	this->initHive();
	this->initBee();
	this->initObjects();
	this->initObjectsS();
	this->initList();
	this->initListS();
	this->interactionWithMap();
	this->initGameOvText();
	this->initTextStart();
}

Game::~Game()
{
	delete this->window;
	delete this->bee;
	delete this->flow1;
	delete this->flow2;
	delete this->hive;

}
//private functions

void Game::initMenu()
{
	if (!this->Menu.loadFromFile("Textures/3.png"))
	{
		std::cout << "Error background";
	}
	this->backgroundMenu.setTexture(this->Menu);

	if (!this->Field1.loadFromFile("Textures/Field1.png"))
	{
		std::cout << "Error field1";
	}
	this->Field1Sp.setTexture(this->Field1);
	this->Field1Sp.setPosition(650, 45);

	if (!this->Field2.loadFromFile("Textures/Field2.png"))
	{
		std::cout << "Error field2";
	}
	this->Field2Sp.setTexture(this->Field2);
	this->Field2Sp.setPosition(45, 645);

	if (!this->GameField.loadFromFile("Textures/1.png"))
	{
		std::cout << "Error GameField";
	}
	this->GamefieldS.setTexture(this->GameField);
	this->GamefieldS.setPosition(45, 45);
}
void Game::interactionWithMap()
{
	for (int i = 70; i < 570; i++)
	{
		for (int j = 70; j < 570; j++)
		{
			
			collision = this->bee->getPos();
			if (collision.x > 496 || collision.x < 70 || collision.y>496 || collision.y < 70)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			//line 1
			else if (collision.x<294&&collision.y==95)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			else if (collision.x > 296 && collision.y==95)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			//line 2
			else if (collision.x < 194 && collision.y == 195)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			else if (collision.x > 396 && collision.y == 195)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			//line4
			else if (collision.x < 194 && collision.y == 395)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			else if (collision.x > 396 && collision.y == 395)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			//line 5
			else if (collision.x<294&&collision.y==495)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			else if (collision.x > 296 && collision.y==495)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			//raw 1
			else if (collision.x == 95 && collision.y < 294)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			else if (collision.x == 95 && collision.y > 296)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			//raw 2
			else if (collision.y < 194 && collision.x == 195)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			else if (collision.y > 396 && collision.x == 195)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			//raw 4
			else if (collision.y < 194 && collision.x == 395)
			{
			this->bee->isAction = false;
			this->bee->isMoveForward = false;
			this->bee->isMoveBack = false;
			this->bee->isMoveRight = false;
			this->bee->isMoveLeft = false;
			}
			else if (collision.y > 396 && collision.x == 395)
			{
			this->bee->isAction = false;
			this->bee->isMoveForward = false;
			this->bee->isMoveBack = false;
			this->bee->isMoveRight = false;
			this->bee->isMoveLeft = false;
			}
			//raw 5
			else if (collision.y < 294 && collision.x == 495)
			{
			this->bee->isAction = false;
			this->bee->isMoveForward = false;
			this->bee->isMoveBack = false;
			this->bee->isMoveRight = false;
			this->bee->isMoveLeft = false;
			}
			else if (collision.y > 296 && collision.x == 495)
			{
			this->bee->isAction = false;
			this->bee->isMoveForward = false;
			this->bee->isMoveBack = false;
			this->bee->isMoveRight = false;
			this->bee->isMoveLeft = false;
			}
			//middle
			else if (collision.y == 295 && collision.x ==200)
			{
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
			}
			else if (collision.y == 295 && collision.x == 375)
			{
			this->bee->isAction = false;
			this->bee->isMoveForward = false;
			this->bee->isMoveBack = false;
			this->bee->isMoveRight = false;
			this->bee->isMoveLeft = false;
			}
			else if (collision.x == 295 && collision.y == 200)
			{
			this->bee->isAction = false;
			this->bee->isMoveForward = false;
			this->bee->isMoveBack = false;
			this->bee->isMoveRight = false;
			this->bee->isMoveLeft = false;
			}
			else if (collision.x == 295 && collision.y == 375)
			{
			this->bee->isAction = false;
			this->bee->isMoveForward = false;
			this->bee->isMoveBack = false;
			this->bee->isMoveRight = false;
			this->bee->isMoveLeft = false;
			}
		}
			
	}

}
//button left
void Game::initTexturesLeft()
{

	if (!this->leftB.loadFromFile("Textures/left.png"))
	{
		std::cout << "Left Button was here";
	}

}

void Game::initSpriteLeft()
{
	this->leftBSprite.setTexture(this->leftB);
	this->leftBSprite.setPosition(100, 690);
}

//right
void Game::initTexturesRight()
{
	if (!this->rightB.loadFromFile("Textures/right.png"))
	{
		std::cout << "Right Button was here";
	}
}

void Game::initSpriteRight()
{
	this->rightBSprite.setTexture(this->rightB);
	this->rightBSprite.setPosition(200, 690);
}

//forward
void Game::initTexturesForward()
{
	if (!this->forwardB.loadFromFile("Textures/forward.png"))
	{
		std::cout << "Forward Button was here";
	}
}

void Game::initSpriteForward()
{
	this->forwardBSprite.setTexture(this->forwardB);
	this->forwardBSprite.setPosition(100, 790);
}
//back
void Game::initTexturesBack()
{
	if (!this->backB.loadFromFile("Textures/down.png"))
	{
		std::cout << "Back Button was here";
	}
}

void Game::initSpriteBack()
{
	this->backBSprite.setTexture(this->backB);
	this->backBSprite.setPosition(200, 790);
}
//pickup
void Game::initTexturesPickup()
{
	if (!this->pickupB.loadFromFile("Textures/pickup.png"))
	{
		std::cout << "Pickup Button was here";
	}
}

void Game::initSpritePickup()
{
	this->pickupBSprite.setTexture(this->pickupB);
	this->pickupBSprite.setPosition(465, 740);
}
//play
void Game::initTexturesPlay()
{
	if (!this->playB.loadFromFile("Textures/Play.png"))
	{
		std::cout << "Back Button was here";
	}
}

void Game::initSpritePlay()
{
	this->playBSprite.setTexture(this->playB);
	this->playBSprite.setPosition(650, 695);
}

void Game::initTexturesRestart()
{
	if (!this->restartB.loadFromFile("Textures/Replay.png"))
	{
		std::cout << "replay Button was here";
	}
}

void Game::initSpriteRestart()
{
	this->restartBSprite.setTexture(this->restartB);
	this->restartBSprite.setPosition(650, 775);
}

void Game::initTexturesExit()
{
	if (!this->exitB.loadFromFile("Textures/exit.png"))
	{
		std::cout << "Exit Button was here";
	}
}

void Game::initSpriteExit()
{
	this->exitBSprite.setTexture(this->exitB);
	this->exitBSprite.setPosition(650, 855);
}



//accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

//functions

void Game::initList()
{
	if (!this->T_List.loadFromFile("Textures/directionTile2.png"))
	{
		std::cout<<"Wrong Direction";
	}
}

void Game::initListS()
{
	this->S_List.setTexture(this->T_List);
}

void Game::initObjects()
{
	if (!this->map.loadFromFile("Textures/Titleset.png"))
	{
		std::cout << "Wrong tileset";
	}
}

void Game::initObjectsS()
{
	this->S_map.setTexture(this->map);
}

void Game::pollEvents()
{
	float time = clock.getElapsedTime().asMilliseconds();
	clock.restart();
	time = time / 800;
	
	
	//event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::MouseButtonPressed:
			sf::Vector2f mousePosWindowF(static_cast<float>(mousePosWindow.x), static_cast<float>(mousePosWindow.y));
			
			if (this->forwardBSprite.getGlobalBounds().contains(mousePosWindowF) && number <= 4 && numberY <= 7 &&!this->hive->IsHome)
			{
				this->isStart = false;
				actions.push_back(1);
				this->List[numberY][number] = '1';
				number++;
				if (number % 4 == 0)
				{
					numberY++;
					number = 0;
				}
			}
			if (this->backBSprite.getGlobalBounds().contains(mousePosWindowF) && number <= 4 && numberY <= 7&&!this->hive->IsHome)
			{
				this->isStart = false;
				actions.push_back(2);
				this->List[numberY][number] = '2';
				number++;
				if (number % 4 == 0)
				{
					numberY++;
					number = 0;
				}
			}
			if (this->rightBSprite.getGlobalBounds().contains(mousePosWindowF) && number <= 4 && numberY <= 7&&!this->hive->IsHome)
			{
				this->isStart = false;
				actions.push_back(3);
				this->List[numberY][number] = '4';
				number++;
				if (number % 4 == 0)
				{
					numberY++;
					number = 0;
				}
			}
			if (this->leftBSprite.getGlobalBounds().contains(mousePosWindowF)&&number<=4&&numberY<=7&&!this->hive->IsHome)
			{
				this->isStart = false;
				this->List[numberY][number] = '3';
				actions.push_back(4);
				number++;
				if (number % 4 == 0)
				{
					numberY++;
					number = 0;
				}
			}
			if (this->pickupBSprite.getGlobalBounds().contains(mousePosWindowF) && number <= 4 && numberY <= 7&&!this->hive->IsHome)
			{
				this->isStart = false;
				this->List[numberY][number] = '5';
				actions.push_back(5);
				number++;
				if (number % 4 == 0)
				{
					numberY++;
					number = 0;
				}
			}
			if (this->playBSprite.getGlobalBounds().contains(mousePosWindowF)&&!this->hive->IsHome&&!actions.empty())
			{
				this->isStart = false;
				actions.push_back(0);
				it = actions.begin();
				this->bee->isAction = true;
				
			}
			if (this->exitBSprite.getGlobalBounds().contains(mousePosWindowF))
			{
				this->window->close();
			}
			if (this->restartBSprite.getGlobalBounds().contains(mousePosWindowF))
			{
				this->hive->IsHome = false;
				this->flow1->flowerExist = true;
				this->flow2->flowerExist = true;
				this->actions.clear();
				this->number = 0;
				this->numberY = 0;
				for (int i = 0; i < HEIGHT_LIST; i++)
					for (int j = 0; j < WIDTH_LIST; j++)
					{
						List[i][j] = '0';
					}
				action = 0;
				this->score = 0; 
				this->bee->isAction = false;
				this->bee->isMoveForward = false;
				this->bee->isMoveBack = false;
				this->bee->isMoveRight = false;
				this->bee->isMoveLeft = false;
				this->bee->changePosition(295, 95);
			}
			break;
		}
	}
	
	if (this->bee->isAction)
	{
			if (!this->bee->isMoveForward && !this->bee->isMoveRight && !this->bee->isMoveLeft && !this->bee->isMoveBack)
			{
				if (it != actions.end()-1)
				{
					action = *it;
					it++;
				}
					
				else if (it == actions.end())
				{
					action = *it;
					this->bee->isAction = false;
				}
			}
	}

	if (action == 1)
	{
		posOfSp = this->bee->getPos();
		this->bee->changeTextures(2);
		this->bee->isMoveForward = true;
		this->bee->isMoveBack = false;
		this->bee->isMoveRight = false;
		this->bee->isMoveLeft = false;
		action = 0;
	}
	if (this->bee->isMoveForward)
	{
		sf::Vector2f posOfSpForw = this->bee->getPos();
		int yFor = posOfSp.y + (-100);
		if (yFor != posOfSpForw.y)
		{
			this->bee->move(0.f, floor(-10.f * time));
			std::cout << std::endl << "FINISH: " << yFor << " " << posOfSp.x << " " << posOfSp.y << "\n";
			std::cout << std::endl << "BEE POSITION" << posOfSpForw.x << " " << static_cast<int>(posOfSpForw.y) << "\n";
		}
		else if (yFor == static_cast<int>(posOfSpForw.y))
		{
			this->bee->isMoveForward = false;
		}
	}

	if (action == 2)
	{
		posOfSp = this->bee->getPos();
		this->bee->changeTextures(3);
		this->bee->isMoveBack = true;
		this->bee->isMoveForward = false;
		this->bee->isMoveRight = false;
		this->bee->isMoveLeft = false;
		action = 0;
	}
	if (this->bee->isMoveBack)
	{
		sf::Vector2f posOfSpBack = this->bee->getPos();
		int yBack = posOfSp.y + 100;
		if (yBack != posOfSpBack.y)
		{
			this->bee->move(0.f, -1 * floor(-10.f * time));
			std::cout << std::endl <<"FINISH: "<< yBack << " " << posOfSp.x << " " << posOfSp.y << "\n";
			std::cout << std::endl << "BEE POSITION" << posOfSpBack.x << " " << static_cast<int>(posOfSpBack.y) << "\n";
		}
		else if (yBack == static_cast<int>(posOfSpBack.y))
		{
			this->bee->isMoveBack = false;
		}
	}

	if (action == 3)
	{
		posOfSp = this->bee->getPos();
		this->bee->changeTextures(4);
		this->bee->isMoveRight = true;
		this->bee->isMoveForward = false;
		this->bee->isMoveBack = false;
		this->bee->isMoveLeft = false;
		action = 0;
	}
	if (this->bee->isMoveRight)
	{
		sf::Vector2f posOfSpRight = this->bee->getPos();
		int yRight = posOfSp.x + 100;
		if (yRight != posOfSpRight.x)
		{
			this->bee->move(-1 * floor(-10.f * time), 0.f);
			std::cout << std::endl << "FINISH: " << yRight << " " << posOfSp.x << " " << posOfSp.y << "\n";
			std::cout << std::endl << "BEE POSITION" << posOfSpRight.x << " " << static_cast<int>(posOfSpRight.y) << "\n";
		}
		else if (yRight == static_cast<int>(posOfSpRight.x))
		{
			this->bee->isMoveRight = false;
		}
	}

	if (action == 4)
	{
		posOfSp = this->bee->getPos();
		this->bee->changeTextures(1);
		this->bee->isMoveLeft = true;
		this->bee->isMoveForward = false;
		this->bee->isMoveBack = false;
		this->bee->isMoveRight = false;
		action = 0;
	}
	if (this->bee->isMoveLeft)
	{
		sf::Vector2f posOfSpLeft = this->bee->getPos();
		int yLeft = posOfSp.x - 100;
		if (yLeft != posOfSpLeft.x)
		{
			this->bee->move(floor(-10.f * time), 0.f);
			std::cout << std::endl << "FINISH: " << yLeft << " " << posOfSp.x << " " << posOfSp.y << "\n";
			std::cout << std::endl << "BEE POSITION" << posOfSpLeft.x << " " << static_cast<int>(posOfSpLeft.y) << "\n";
		}
		else if (yLeft == static_cast<int>(posOfSpLeft.x))
		{
			this->bee->isMoveLeft = false;
		}
	}
	if (action == 5)
	{
		collision = this->bee->getPos();
		if (this->flow1->getPosFlow().contains(collision))
		{
			this->flow1->flowerExist = false;
			this->score++;
		}
		else if (this->flow2->getPosFlow().contains(collision))
		{
			this->flow2->flowerExist = false;
			this->score++;
		}
		else if (this->hive->getPosHive().contains(collision))
		{
			this->hive->IsHome = true;
			action = 0;
			this->bee->isAction = false;
			this->bee->isMoveForward = false;
			this->bee->isMoveBack = false;
			this->bee->isMoveRight = false;
			this->bee->isMoveLeft = false;
		}
	}
}

void Game::updateMousePosotion()
{
	/*
	* @return void
	* update the mous eposition:
	* - mouse position relative to window (vector2i)
	*/
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	
}


void Game::update()
{
	this->pollEvents();
	//uodate mouse position
	// relativ to the screen
	//std::cout << sf::Mouse::getPosition().x<<" "<< sf::Mouse::getPosition().y<<std::endl;
	//relativ to the window
	this->interactionWithMap();
	this->updateMousePosotion();
	//move
	

}

void Game::renderBackground()
{
	this->window->draw(this->backgroundMenu);
	this->window->draw(this->Field1Sp);
	this->window->draw(this->Field2Sp);
	this->window->draw(this->GamefieldS);
}

void Game::render()
{
	/*
	* @return void
	* -clear new frame
	* -render objects
	* - display frame in window
	* renders the game objects
	*/
	this->window->clear();
	//draw menu
	this->renderBackground();
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == ' ') this->S_map.setTextureRect(sf::IntRect(200, 0, 100, 100));
			if (TileMap[i][j] == '9')
			{
				this->S_map.setTextureRect(sf::IntRect(100, 0, 100, 100)); 
			}
			if (TileMap[i][j] == '1')
			{
				this->S_map.setTextureRect(sf::IntRect(0, 0, 100, 100));
			}
			this->S_map.setPosition(j * 100+70, i * 100+70);
			this->window->draw(S_map);
		}

	for (int i = 0; i < HEIGHT_LIST; i++)
		for (int j = 0; j < WIDTH_LIST; j++)
		{
			if (List[i][j] == '0') this->S_List.setTextureRect(sf::IntRect(400, 0, 80, 80));
			if (List[i][j] == '1') this->S_List.setTextureRect(sf::IntRect(0, 0, 80, 80));
			if (List[i][j] == '2') this->S_List.setTextureRect(sf::IntRect(80, 0, 80, 80));
			if (List[i][j] == '3') this->S_List.setTextureRect(sf::IntRect(160, 0, 80, 80));
			if (List[i][j] == '4') this->S_List.setTextureRect(sf::IntRect(240, 0, 80, 80));
			if (List[i][j] == '5') this->S_List.setTextureRect(sf::IntRect(320, 0, 80, 80));
			this->S_List.setScale(0.7f, 0.7f);
			this->S_List.setPosition(j * 70 + 670, i * 70 + 65);
			this->window->draw(S_List);
		}
	this->hive->renderHive(*this->window);
	if(this->flow1->flowerExist)
	this->flow1->renderFlower(*this->window);
	if (this->flow2->flowerExist)
	this->flow2->renderFlower(*this->window);
	this->bee->render(*this->window);
	this->window->draw(this->backBSprite);
	this->window->draw(this->rightBSprite);
	this->window->draw(this->forwardBSprite);
	this->window->draw(this->leftBSprite);
	this->window->draw(this->playBSprite);
	this->window->draw(this->pickupBSprite);
	this->window->draw(this->restartBSprite);
	this->window->draw(this->exitBSprite);
	if (this->hive->IsHome)
	{
		this->window->draw(this->mainText);
		this->window->draw(this->pointsText);
		this->window->draw(this->madeBy);
	}
	if (this->isStart) 
	{
		this->window->draw(this->startText);
		this->window->draw(this->startText2);
	}
	this->window->display();
}





