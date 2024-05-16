#include"sunFlower.hpp"

using namespace sf;
SunFlower :: SunFlower(Vector2f pose, int blocks)
{
    if (!image.loadFromFile("spriters/sunflower/Sunflower.png")|| !sunImage.loadFromFile("spriters/images/sun.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    sprite.setScale(0.04, 0.04);
    sprite.setPosition(pose);
    
    sunSprite.setTexture(sunImage);
    sunSprite.setOrigin(sunSprite.getPosition().x + sunSprite.getTextureRect().width/2 , sunSprite.getPosition().x + sunSprite.getTextureRect().height/2 );
    sunSprite.setScale(0.45,0.45);
    sunSprite.setPosition(pose);
    block = blocks;
    isCollided = false;
    isSun = false;
    life = sunFlowerLife;
}

void SunFlower :: collided()
{
    Time time = clock.getElapsedTime();
    if (isCollided)
    {
        if (time.asMilliseconds() >= 1000 && life!=0)
        {
            life--;
            clock.restart();
        }
    } 
}

void SunFlower :: sunGenerator(RenderWindow &window, int &storage)
{
    Event event;
    Vector2f mousePose = Vector2f(Mouse :: getPosition(window));
    Time time = sunClock.getElapsedTime();
    if (time.asMilliseconds() >= 7000 && !isSun)
    {
        isSun = true;
        sunClock.restart();
    }
    if (isSun && sunSprite.getGlobalBounds().contains(mousePose))
    {
        isSun = false;
        storage += sunFlowerQuantity;
    }
}

void SunFlower :: render(RenderWindow &window)
{ 
    window.draw(sprite);
    if (isSun)
    {
        window.draw(sunSprite);
    }
}
