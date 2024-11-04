#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Door
{
private:
Animation animation;

public:
	Door(sf::Texture* texture, sf::Vector2f position, bool locked, float switchTime);
	~Door() = default;
};
