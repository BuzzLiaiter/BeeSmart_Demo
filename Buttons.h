#pragma once

class Buttons
{
public:
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

	//priv functions
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

public:
	Buttons();
	~Buttons();
	//funktions
	void update();
	void render(sf::RenderTarget& targetN);
};

