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
    x.push_back(100);x.push_back(150);x.push_back(200);x.push_back(250);x.push_back(300);x.push_back(350);x.push_back(400);
    position.x = x[rand()%7];
    position.y = 50;//-sunTexture.getSize().y;
    sunSprite.setPosition(position);

    fallSpeed = 0.70f;
}

void RandomSun::render(RenderWindow &window)
{
    window.draw(sunSprite);
}

void RandomSun::update()
{
    position.y += fallSpeed;
    sunSprite.setPosition(position);
}
