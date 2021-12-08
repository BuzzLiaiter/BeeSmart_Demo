#include "Flower.h"

void Flower::initFlower()
{
		if (!this->Flower_T.loadFromFile("Textures/flower.png"))
		{
			std::cout << "Wrong flower num1";
		}
}

void Flower::initFlowerS()
{
	this->Flower_S.setTexture(this->Flower_T);
	this->Flower_S.setPosition(70, 270);
}
Flower::Flower()
{
	this->flowerExist = true;
	this->initFlower();
	this->initFlowerS();
}

Flower::~Flower()
{
}

sf::FloatRect Flower::getPosFlow()
{
	return this->Flower_S.getGlobalBounds();
}

void Flower::changePosition(float x, float y)
{
	this->Flower_S.setPosition(x, y);
}

void Flower::updateFlower()
{
}

void Flower::renderFlower(sf::RenderTarget& target)
{
	target.draw(this->Flower_S);
}

