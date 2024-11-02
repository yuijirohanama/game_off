#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
private:
    sf::RectangleShape& body;
    float depth;
public:
    Collider(sf::RectangleShape& body, float Subtractdepth);
    ~Collider();

    void Move(float dx, float dy) {body.move(dx, dy);}


    bool checkCollision(Collider& other, float pushDistance);
    sf::Vector2f getPosition();
    sf::Vector2f getHalfSize() {return (body.getSize()-sf::Vector2f(0.0f, depth)) / 2.0f; }
};

