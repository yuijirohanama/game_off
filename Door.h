#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"



class Door
{
private:
Animation animation;
bool open;
sf::RectangleShape body;
unsigned int row;


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
	void Open();
	Collider GetCollider() {return Collider(body, 0.0f); }
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
private:



Direction direction;
};

