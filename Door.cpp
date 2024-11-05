#include "Door.h"
#include <iostream>

Door::Door(sf::Texture* texture, sf::Vector2f position, bool locked, float switchTime, Direction direction) : animation(texture, sf::Vector2u(6,4), switchTime)
{
this->direction = direction;
body.setSize(sf::Vector2f(100.0f, 234.0f));
body.setOrigin(body.getSize() / 2.0f);
body.setPosition(position);
body.setTexture(texture);
if (direction == up)
{
    row = 0;
}
else if (direction == down)
{
    row = 1;
}
else if (direction == right)
{
    row = 2;
}
else
{
    row = 3;
}
body.setTextureRect(animation.UVrect);
}

void Door::Open() {
    open = true;
}

void Door::Update(float deltaTime) {

if (int i = 0; open == true && i <5)
{
animation.Update(row, deltaTime, 0,true);
body.setTextureRect(animation.UVrect);
i++;
}

}

void Door::Draw(sf::RenderWindow& window) {
    window.draw(body);
}