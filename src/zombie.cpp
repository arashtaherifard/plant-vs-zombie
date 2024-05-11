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
    sprite.setScale(0.22,0.22);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    y.push_back(75);y.push_back(200);y.push_back(330);y.push_back(510);y.push_back(400);
    pose.x = 1300 ;
    pose.y = y[rand()%5];
    life = 3;
}

void Zombie :: update()
{
    pose.x -= 0.3;
}

void Zombie :: render(RenderWindow  &window)
{
    sprite.setPosition(pose);
    update();
    window.draw(sprite);
}
