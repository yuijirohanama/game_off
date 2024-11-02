#include "Collider.h"
#include <iostream>

Collider::Collider(sf::RectangleShape& body) :
    body(body)
{
    
}

bool Collider::checkCollision(Collider& other, float pushDistance)
{
    sf::Vector2f otherPosition = other.getPosition();
    sf::Vector2f otherHalfSize = other.getHalfSize();
    sf::Vector2f thisPosition = getPosition();
    sf::Vector2f thisHalfSize = getHalfSize();
    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float intersectX = abs(deltaX) - abs(otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - abs(otherHalfSize.y + thisHalfSize.y);

    if (intersectX < 0.0f && intersectY < 0.0f)
    {
        
        pushDistance = std::min(std::max(pushDistance, 0.0f), 1.0f);
        if (intersectX > intersectY)
        {
            if (deltaX > 0.0f)
            {
                Move(intersectX * (1.0f - pushDistance), 0.0f);
                other.Move(-intersectX * pushDistance, 0.0f);
            }
            else
            {
                Move(-intersectX * (1.0f - pushDistance), 0.0f);
                other.Move(intersectX * pushDistance, 0.0f);
            }
            
            
        }
        else
        {
         
            if (deltaY > 0.0f)
            {
                Move(0.0f, intersectY * (1.0f - pushDistance));
                other.Move(0.0f, -intersectY * pushDistance);
            }
            else
            {
                Move(0.0f, -intersectY * (1.0f - pushDistance));
                other.Move(0.0f, intersectY * pushDistance);
            }
        }
        
        return true;
    }
    
    
    return false;
}

sf::Vector2f Collider::getPosition() 
    {
        return body.getPosition();
    }


Collider:: ~Collider()
 {

 }