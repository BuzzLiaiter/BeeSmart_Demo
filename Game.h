#pragma once
#include "Flower.h"
#include "TheBee.h"
#include "Hive.h"
const int HEIGHT_MAP = 5;
const int WIDTH_MAP = 5;
const int HEIGHT_LIST = 8;
const int WIDTH_LIST = 4;


/*
   class that acts as game engine.
   wrapper class
*/

class Game
{
private:
	int score;
	//variables
	bool endGame;
	//game Menu
	sf::Texture Menu;
	sf::Sprite backgroundMenu;
	sf::Texture Field1;
	sf::Sprite Field1Sp;
	sf::Texture Field2;
	sf::Sprite Field2Sp;
	sf::Texture GameField;
	sf::Sprite GamefieldS;
	

	//player
	TheBee* bee;
	//objects
	Flower* flow1;
	Flower* flow2;
	Hive* hive;
	//buttons;
	//left
	sf::Sprite leftBSprite;
	sf::Texture leftB;
	//right
	sf::Sprite rightBSprite;
	sf::Texture rightB;
	//forward
	sf::Sprite forwardBSprite;
	sf::Texture forwardB;
	//back
	sf::Sprite backBSprite;
	sf::Texture backB;
	//pickup
	sf::Sprite pickupBSprite;
	sf::Texture pickupB;
	//play
	sf::Sprite playBSprite;
	sf::Texture playB;
	//restart
	sf::Sprite restartBSprite;
	sf::Texture restartB;
	//exit
	sf::Sprite exitBSprite;
	sf::Texture exitB;

	//game over texts
	sf::Font font;
	sf::Text mainText;
	sf::Text pointsText;
	sf::Text madeBy;

	//start game text
	sf::Font start;
	sf::Text startText;
	sf::Text startText2;
	void initTextStart();

	//priv functions;

	void initFlower();
	void initFlower2();

	void initHive();
	void initGameOvText();
	
	//left
	void initTexturesLeft();
	void initSpriteLeft();
	//right
	void initTexturesRight();
	void initSpriteRight();
	//forward
	void initTexturesForward();
	void initSpriteForward();
	//forward
	void initTexturesBack();
	void initSpriteBack();
	//pickup
	void initTexturesPickup();
	void initSpritePickup();
	//play
	void initTexturesPlay();
	void initSpritePlay();
	//restart
	void initTexturesRestart();
	void initSpriteRestart();
	//exit
	void initTexturesExit();
	void initSpriteExit();
	//window

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	//mouse position
	sf::Vector2i mousePosWindow;
	//private functions
	void initVariables();
	void initWindow();
	void initBee();
public:
	//konstructors and destructors 
	Game();
	virtual ~Game();
	//map
	sf::String TileMap[HEIGHT_MAP] = {
	"99199",
	"91119",
	"11911",
	"91119",
	"99199",
	};
	sf::String List[HEIGHT_LIST] = {
		"0000",
		"0000",
		"0000",
		"0000",
		"0000",
		"0000",
		"0000",
		"0000",
	};
	sf::Texture map;
	sf::Sprite S_map;
	sf::Texture T_List;
	sf::Sprite S_List;
	int number;
	int numberY;
	//accessors
	const bool running() const;
	bool isStart;
	int action;
	std::vector<int> actions;
	std::vector<int>::iterator it;
	sf::Clock clock;
	sf::Vector2f posOfSp;
	sf::Vector2f collision;
	//functios
	void initList();
	void initListS();
	void initObjects();
	void initObjectsS();
	void pollEvents();
	void updateMousePosotion();
	void update();
	void renderBackground();
	void render();
	void initMenu();
	void interactionWithMap();
};

