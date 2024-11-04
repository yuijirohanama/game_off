#include "Door.h"

Door::Door(sf::Texture* texture, sf::Vector2f position, bool locked, float switchTime) : animation(texture, sf::Vector2u(6, 0), switchTime)
{
    
}