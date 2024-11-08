#include "Door.h"
#include <iostream>

Door::Door(sf::Texture* texture, sf::Vector2f position, bool locked, float switchTime, Direction direction) : animation(texture, sf::Vector2u(6,4), switchTime)
{
this->direction = direction;
body.setSize(sf::Vector2f(100.0f, 234.0f));
body.setOrigin(body.getSize() / 2.0f);
body.setPosition(position);
body.setTexture(texture);
i = 5;

if (direction == 0)
{
    row = 0;
}
if (direction == 1)
{
    row = 1;
    std::cout<<direction<<std::endl;
}
if (direction == 3)
{
    row = 2;
}
else if(direction == 2)
{
    row = 3;
}

body.setTextureRect(animation.UVrect);
}

void Door::Open() {
    open = true;
}

void Door::Update(float deltaTime) {
static bool isFirstTime = true;

// Inside the function
if (isFirstTime) {
  animation.Update(row, deltaTime, 5,true);
  body.setTextureRect(animation.UVrect);
  isFirstTime = false;
}
if (open == true && animation.GetColumn()<i)
{
animation.Update(row, deltaTime, 0,true);
body.setTextureRect(animation.UVrect);
std::cout<<animation.GetColumn()<<std::endl;


}





}

void Door::Draw(sf::RenderWindow& window) {
    window.draw(body);
}