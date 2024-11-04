#include "Door.h"
#include <iostream>

Door::Door(sf::Texture* texture, sf::Vector2f position, bool locked, float switchTime, Direction direction) : animation(texture, sf::Vector2u(6, 0), switchTime)
{
this->direction = direction;
}

