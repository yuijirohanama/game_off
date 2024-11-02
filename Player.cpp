#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
    animation(texture, imageCount, switchTime)
{
    this -> speed = speed;
    row = 0;
    faceRight = true;
    emptyImages = 0;
    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(70.0f, -76.0f);
	body.setTexture(texture);
}

void Player::Update(float deltaTime) 
{
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= speed * deltaTime;
    }

     if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movement.y -= speed * deltaTime;
    }

     if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement.y += speed * deltaTime;
    }
    
    if (movement.x == 0.0f)
    {
        row = 0;
        emptyImages = 0;
    }
    else
    {
        row = 1;
        emptyImages = 5;
        if (movement.x > 0.0f) 
            faceRight = true;
        else
            faceRight = false;
        
        
    }   
    animation.Update(row, deltaTime, emptyImages,faceRight);
    body.setTextureRect(animation.UVrect);
    body.move(movement); 

}



void Player::Draw(sf::RenderWindow& window) 
{
    window.draw(body);

}