#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;


    float totalTime;
    float switchTime;
public:    
    sf::IntRect UVrect;
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();
    unsigned int GetColumn() {return currentImage.x;}
    void Update(int row, float deltaTime, int emptyImages, bool faceRight);
};

