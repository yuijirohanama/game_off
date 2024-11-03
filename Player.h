#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player
{
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
    unsigned int emptyImages;
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    struct State
    {
        char name[15];
        sf::Vector2f Hitbox_size;
        sf::Vector2f Hitbox_pos;
        int damage;

    };
    
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    sf::Vector2f GetPosition() {return body.getPosition(); }
    Collider GetCollider() {return Collider(body, 80.0f); }
};

//player is 21 pixels high make doors 25 px or something