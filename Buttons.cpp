#include "Buttons.h"


//button left
void Buttons::initTexturesLeft()
{
	
	if (!this->leftB.loadFromFile("Textures/left.png"))
	{
		std::cout << "Left Button was here";
	}

}

void Buttons::initSpriteLeft()
{
	this->leftBSprite.setTexture(this->leftB);
	this->leftBSprite.setPosition(50, 300);
}

//right
void Buttons::initTexturesRight()
{
	if (!this->rightB.loadFromFile("Textures/right.png"))
	{
		std::cout << "Right Button was here";
	}
}

void Buttons::initSpriteRight()
{
	this->rightBSprite.setTexture(this->rightB);
	this->rightBSprite.setPosition(50, 400);
}

//forward
void Buttons::initTexturesForward()
{
	if (!this->forwardB.loadFromFile("Textures/forward.png"))
	{
		std::cout << "Forward Button was here";
	}
}

void Buttons::initSpriteForward()
{
	this->forwardBSprite.setTexture(this->forwardB);
	this->forwardBSprite.setPosition(50, 100);
}

void Buttons::initTexturesBack()
{
	if (!this->backB.loadFromFile("Textures/down.png"))
	{
		std::cout << "Back Button was here";
	}
}

void Buttons::initSpriteBack()
{
	this->backBSprite.setTexture(this->backB);
	this->backBSprite.setPosition(50, 200);
}

void Buttons::initTexturesPickup()
{
}

void Buttons::initSpritePickup()
{
}

void Buttons::initTexturesPlay()
{
}

void Buttons::initSpritePlay()
{
}

void Buttons::initTexturesRestart()
{
}

void Buttons::initSpriteRestart()
{
}

void Buttons::initTexturesExit()
{
}

void Buttons::initSpriteExit()
{
}

Buttons::Buttons()
{
	this->initTexturesLeft();
	this->initSpriteLeft();
	this->initTexturesRight();
	this->initSpriteRight();
	this->initTexturesBack();
	this->initSpriteBack();
	this->initTexturesForward();
	this->initSpriteForward();
}

Buttons::~Buttons()
{
}

void Buttons::update()
{
}

void Buttons::render(sf::RenderTarget& targetN)
{
	targetN.draw(this->leftBSprite);
	targetN.draw(this->rightBSprite);
	targetN.draw(this->forwardBSprite);
	targetN.draw(this->backBSprite);

}
