#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this ->imageCount = imageCount;
    this ->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    UVrect.width = texture ->getSize().x / float(imageCount.x);
    UVrect.height = texture ->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime, int emptyImages, bool faceRight)
{
    currentImage.y = row;
    totalTime += deltaTime;
    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
            if (currentImage.x >= imageCount.x - emptyImages)
            {
                currentImage.x = 0;
            }
            
    }

    UVrect.top = (currentImage.y * UVrect.height); 

    if (faceRight)
    {
        UVrect.left = currentImage.x * abs(UVrect.width);
        UVrect.width = abs(UVrect.width);
    }
    else
    {
        UVrect.left = (currentImage.x + 1) * abs(UVrect.width);
        UVrect.width = -abs(UVrect.width);
    }
    
       
}