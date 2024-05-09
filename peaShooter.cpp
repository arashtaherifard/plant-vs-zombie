#include"peaShooter.hpp"
PS :: PS(int x, int y)
{
    Clock internal;
    if (!image.loadFromFile("Peashooter.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite . setScale(0.045, 0.045);
    // sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    // sprite.setPosition(30,30);
    
}

void PS :: handleMousePress(Vector2f mousePose)
{
    isDragging = true ;
}

void PS :: handleMouseRelease(Vector2f Pose)
{
    isDragging = false;
}

void PS :: update(Vector2f pose)
{
    if(isDragging) 
    {
        sprite.setPosition(pose);
    }
}

void PS :: render(RenderWindow &window)
{
    window.draw(sprite);
    Time time = clock.getElapsedTime();
    if(time.asMilliseconds() >= 500)
    {
        clock.restart();
        projectiles.push_back(new Projectile(Vector2f(sprite.getPosition())));
    }
    
    for (int i = 0; i < projectiles.size(); i++)
    {
        
        projectiles[i]->render(window);
    }
}