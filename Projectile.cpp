#include "Projectile.h"
#include <math.h>
#include <iostream>

Projectile::Projectile(sf::Texture* texture, sf::Vector2f position, float speed, sf::Vector2f targetPosition)
{
    body.setTexture(texture);
    body.setSize(sf::Vector2f(20.0f, 20.0f));
    body.setPosition(position);
    this -> speed = speed;
    float deltaX = targetPosition.x - position.x;
    float deltaY = targetPosition.y - position.y;
    rotation = atan2(deltaY, deltaX);
}

void Projectile::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);


    
    if (((rotation * 180) / M_PI) >= 180)
    {
        movement.x = sin(rotation) * (speed * deltaTime);
        movement.y = cos(rotation) * (speed * deltaTime);
    }
    else
    {
        movement.x = cos(rotation) * (speed * deltaTime);
        movement.y = sin(rotation) * (speed * deltaTime);
    }
    
    
    
    
    body.move(movement);
}

Projectile::~Projectile()
{

}

void Projectile::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

