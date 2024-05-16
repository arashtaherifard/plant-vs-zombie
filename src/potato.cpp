#include"potato.hpp"

potato :: potato(Vector2f pose, int blocks)
{
    if (!image.loadFromFile("spriters/wall-nut/Wallnut_body.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    sprite.setScale(0.55, 0.55);
    sprite.setPosition(pose);
    life = potatoLife;
    isCollided = false;
    block = blocks;
}

void potato :: collided()
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

void potato :: render(RenderWindow &window)
{
    window.draw(sprite);
}
