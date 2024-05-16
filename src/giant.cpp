#include"giant.hpp"
#include <cstdlib>
Giant :: Giant()
{
    for (int i = 0; i < 10; i++)
    {    
        Texture texture;
        if (!texture.loadFromFile("spriters/Animations/QQ/"+to_string(i+1)+".png"))
        {
            cout << "cant open"<<endl;
            return;
        }    
        images.push_back(texture);
    }  
    sprite.setTexture(images[0]);
    sprite.setScale(0.2,0.2);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    y.push_back(110);y.push_back(220);y.push_back(310);y.push_back(525);y.push_back(420);
    pose.x = 1300 ;
    pose.y = y[rand()%5];
    life = giantLife;
    isFreezed = false;
    isCollided = false;
}

void Giant :: update()
{
    Time time = clock.getElapsedTime();
    if(!isCollided)
    {
        if(!isFreezed)
        {
            if (frameClock.getElapsedTime().asSeconds()>0.1f)
            {
                currentFrame = (currentFrame + 1) % images.size();
                sprite.setTexture(images[currentFrame]);
                frameClock.restart();
            }
            pose.x -= giantSpeed;
        }
        else
        {
            Time time = clock.getElapsedTime();
            if (frameClock.getElapsedTime().asSeconds()>0.1f)
            {
                currentFrame = (currentFrame + 1) % images.size();
                sprite.setTexture(images[currentFrame]);
                frameClock.restart();
            }
            pose.x -= giantFrozenSpeed;
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
