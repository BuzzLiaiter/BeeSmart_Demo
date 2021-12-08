#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class Hive
{
private:
	sf::Texture Hive_T;
	sf::Sprite Hive_S;
	void initHive();
	void initHiveS();
public:
	Hive();
	~Hive();
	bool IsHome;
	sf::FloatRect getPosHive();
	void updateHive();
	void renderHive(sf::RenderTarget& target);
};

