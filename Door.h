#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Door
{
private:
Animation animation;



public:
enum Direction
{
up,
down,
left,
right,
};
	Door(sf::Texture* texture, sf::Vector2f position, bool locked, float switchTime, Direction direction);
	~Door() = default;
private:
Direction direction;
};

