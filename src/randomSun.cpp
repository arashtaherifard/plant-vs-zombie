#include "randomSun.hpp"

using namespace sf;

RandomSun::RandomSun()
{
    if (!sunTexture.loadFromFile("spriters/images/sun.png"))
    {
        // Handle error
    }
    sunSprite.setTexture(sunTexture);
    sunSprite.setOrigin(sunTexture.getSize().x / 2, sunTexture.getSize().y / 2);
    sunSprite.setScale(0.7,0.7);
    position.x = rand()%1400;
    position.y = 0;
    sunSprite.setPosition(position);
    fallSpeed = 0.70f;
}

void RandomSun :: render(RenderWindow &window)
{
    window.draw(sunSprite);
}

void RandomSun::update()
{
    position.y += fallSpeed;
    sunSprite.setPosition(position);
}
