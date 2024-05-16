#include"giant.hpp"
#include <cstdlib>
Giant :: Giant()
{
    if (!image.loadFromFile("spriters/giant/1.png"))
    {
        return;
    }    
    sprite.setTexture(image);
    sprite.setScale(0.2,0.2);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    y.push_back(110);y.push_back(220);y.push_back(310);y.push_back(525);y.push_back(420);
    pose.x = 1300 ;
    pose.y = y[rand()%5];
    life = 15;
    isFreezed = false;
    isCollided = false;
}

void Giant :: update()
{
    if(!isCollided)
    {
        if(!isFreezed)
        {
            pose.x -= 0.2;
        }
        else
        {
            Time time = clock.getElapsedTime();
            pose.x -= 0.05;
            if (time.asMilliseconds() >= 6000)
            {
                isFreezed = false;
                clock.restart();
            }
        }
    }
    
}

void Giant :: render(RenderWindow  &window)
{
    sprite.setPosition(pose);
    update();
    window.draw(sprite);
}
