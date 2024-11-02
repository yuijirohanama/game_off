#include "UiObject.h"


UiObject::UiObject(sf::Texture* texture, sf::Vector2u imageCount) 
{
    sf::Vector2u currentImage;
    currentImage.x = 0;
    UVrect.width = texture ->getSize().x / float(imageCount.x);
    UVrect.height = texture ->getSize().y / float(imageCount.y);
}

void UiObject::Update(int row, bool faceRight, int column) 
{
    currentImage.y = column;
    UVrect.top = (currentImage.y * UVrect.height);
    currentImage.x = row;
    UVrect.left = currentImage.x * abs(UVrect.width);
    UVrect.width = abs(UVrect.width);
}

