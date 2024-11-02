#pragma once
#include <SFML/Graphics.hpp>

class UiObject
{
public:
	UiObject(sf::Texture* texture, sf::Vector2u imageCount);
	~UiObject() = default;
	void Update(int row, bool faceRight, int column);
private:
sf::Texture* texture;
sf::Vector2u imageCount;
sf::Vector2u currentImage;
public:
sf::IntRect UVrect;

};
