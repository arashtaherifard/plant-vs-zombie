#include"snowShooter.hpp"

SS :: SS(Vector2f pose, int blocks)
{
    if (!image.loadFromFile("spriters/snow/HDplus_snowpea.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite.setScale(0.06, 0.06);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    sprite.setPosition(pose);
    block = blocks;
    isCollided = false;
    life = 6;
}

void SS :: collided()
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

void SS :: render(RenderWindow &window)
{
    window.draw(sprite);
}