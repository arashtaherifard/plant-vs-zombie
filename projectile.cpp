#include"projectile.hpp"
Projectile :: Projectile()
{
    if (!image.loadFromFile("spriters/Peashooter/pea.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite.setScale(0.2,0.2);
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
    sprite.setPosition(spritePose.x+5, spritePose.y-25);
    window.draw(sprite);
}