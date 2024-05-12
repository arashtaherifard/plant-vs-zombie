#include"snow.hpp"
Snow :: Snow(Vector2f pose)
{
    if (!image.loadFromFile("spriters/snow pea/ProjectileSnowPea.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite.setScale(0.2,0.2);
    spritePose = pose;
}

void Snow  :: update()
{
    spritePose.x += 3 ; 
}

void Snow :: render(RenderWindow  &window)
{
    sprite.setPosition(spritePose.x + 4, spritePose.y-25);
    update();
    window.draw(sprite);
}