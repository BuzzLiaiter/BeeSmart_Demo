#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cmath>


class TheBee
{
private:
	
	sf::Sprite sprite;
	sf::Texture texture;
	float movementSpeed;

	//priv functions
	void initTextures();
	void initSprite();
public: 
	TheBee();
	~TheBee();
	bool isMoveForward;
	bool isMoveBack;
	bool isMoveRight;
	bool isMoveLeft;
	bool isAction;
//functios
	void changePosition(float x, float y);
	sf::Vector2f getPos();
	void changeTextures(int n);
	sf::FloatRect getBounds();
	void move(const float dirX, const float dirY);
	void update();
	void render(sf::RenderTarget& target);
};


