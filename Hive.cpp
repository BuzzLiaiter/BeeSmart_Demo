#include "Hive.h"

void Hive::initHive()
{
	if (!this->Hive_T.loadFromFile("Textures/Hive2.png"))
	{
		std::cout << "wRONG HIVE";
	}
}

void Hive::initHiveS()
{
	this->Hive_S.setTexture(this->Hive_T);
	this->Hive_S.setPosition(470, 270); 
}

Hive::Hive()
{
	this->IsHome = false;
	this->initHive();
	this->initHiveS();
}

Hive::~Hive()
{
}

sf::FloatRect Hive::getPosHive()
{
	return this->Hive_S.getGlobalBounds();
}

void Hive::updateHive()
{
}

void Hive::renderHive(sf::RenderTarget& target)
{
	target.draw(this->Hive_S);
}
