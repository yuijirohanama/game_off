#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
private:
    sf::RectangleShape& body;
public:
    Collider(sf::RectangleShape& body);
    ~Collider();

    void Move(float dx, float dy) {body.move(dx, dy);}


    bool checkCollision(Collider& other, float pushDistance);
    sf::Vector2f getPosition();
    sf::Vector2f getHalfSize() {return body.getSize() / 2.0f; }
};

