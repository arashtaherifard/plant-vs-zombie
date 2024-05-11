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

void Projectile :: update()
{
    spritePose.x += 3 ; 
}

void Projectile :: render(RenderWindow  &window)
{
    sprite.setPosition(spritePose.x + 4, spritePose.y-25);
    update();
    window.draw(sprite);
}