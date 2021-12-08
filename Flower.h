#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class Flower
{
private:
	sf::Texture Flower_T;
	sf::Sprite Flower_S;
	

	void initFlower();
	void initFlowerS();
public:
	Flower();
	~Flower();
	bool flowerExist;
	sf::FloatRect getPosFlow();
	void changePosition(float x, float y);
	void updateFlower();
	void renderFlower(sf::RenderTarget& target);
};

