#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Projectile
{
private:
    sf::RectangleShape body;
    float speed;
    float rotation;

public:
    Projectile(sf::Texture* texture, sf::Vector2f position, float speed, sf::Vector2f targetPosition);
    ~Projectile();
    void Draw(sf::RenderWindow& window);
    void Update(float deltaTime);
};

