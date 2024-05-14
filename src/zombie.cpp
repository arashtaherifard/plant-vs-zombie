#include"zombie.hpp"
#include <cstdlib>
Zombie :: Zombie()
{
    if (!image.loadFromFile("spriters/zombie/Zombie_healthy.png"))
    {
        return;
    }    
    srand((unsigned) time(NULL));
    sprite.setTexture(image);
    sprite.setScale(0.2,0.2);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    y.push_back(110);y.push_back(220);y.push_back(310);y.push_back(525);y.push_back(420);
    pose.x = 1300 ;
    pose.y = y[rand()%5];
    life = 5;
    isCollided = false;
}

void Zombie :: update()
{
    if(!isCollided)
        pose.x -= 0.2;
    
}

void Zombie :: render(RenderWindow  &window)
{
    sprite.setPosition(pose);
    update();
    window.draw(sprite);
}
