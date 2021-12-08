#include "TheBee.h"

void TheBee::initTextures()
{
	//load textures
	if (!this->texture.loadFromFile("Textures/Bee_right.png"))
	{
		std::cout << "Bee was here:(";
	}
}

void TheBee::initSprite()
{
	//set sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(295, 95);
	//resize
	//this->sprite.scale(1.f,1.f) -- 100%
}

TheBee::TheBee()
{
	this->movementSpeed = 1.f;
	this->initTextures();
	this->initSprite();
	this->isMoveForward = false;
	this->isMoveBack = false;
	this->isMoveRight = false;
	this->isMoveLeft = false;
	this->isAction = false;
	this->getBounds();
}

TheBee::~TheBee()
{
}
void TheBee::changePosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}
sf::Vector2f TheBee::getPos()
{
	return this->sprite.getPosition();
}
void TheBee::changeTextures(int n)
{
	switch (n)
	{
	case 1:
		if (!this->texture.loadFromFile("Textures/Bee_left.png"))
		{
			std::cout << "Bee was here:(";
		}
		break;
	case 2:
		if (!this->texture.loadFromFile("Textures/bee_forward.png"))
		{
			std::cout << "Bee was here:(";
		}
		break;
	case 3:
		if (!this->texture.loadFromFile("Textures/Bee-back.png"))
		{
			std::cout << "Bee was here:(";
		}
		break;
	case 4:
		if (!this->texture.loadFromFile("Textures/Bee_right.png"))
		{
			std::cout << "Bee was here:(";
		}
		break;
	}
	
}
sf::FloatRect TheBee::getBounds()
{
	return this->sprite.getGlobalBounds();
}
//functions
void TheBee::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void TheBee::update()
{

}

void TheBee::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
