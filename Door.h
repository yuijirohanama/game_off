#pragma once
#include <SFML/Graphics.hpp>

class Door
{
private:
	sf::RectangleShape& body;

public:
	Door(sf::RectangleShape& body, sf::Vector2f position, bool locked);
	~Door() = default;
};
