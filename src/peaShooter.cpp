#include"peaShooter.hpp"
PS :: PS(Vector2f pose, int count)
{
    
    if (!image.loadFromFile("spriters/Peashooter/Peashooter.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite.setScale(0.04, 0.04);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    sprite.setPosition(pose);
    life = 5;
    isCollided = false;
    block = count;
    
}

void PS :: collided()
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

void PS :: render(RenderWindow &window)
{
    window.draw(sprite);
}