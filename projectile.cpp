#include"projectile.hpp"
Projectile :: Projectile(Vector2f pose)
{
    if (!image.loadFromFile("spriters/Peashooter/pea.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite.setScale(0.2,0.2);
    spritePose = pose;
}

void Projectile :: mover()
{
    spritePose.x += 5 ; 
}

// void PS :: update(Vector2f pose)
// {

// }

void Projectile :: render(RenderWindow  &window)
{
    mover();
    sprite.setPosition(spritePose);
    window.draw(sprite);
}