#include"snowShooter.hpp"

SS :: SS(Vector2f pose, int blocks)
{
    if (!image.loadFromFile("spriters/snow/HDplus_snowpea.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite . setScale(0.06, 0.06);
    sprite.setPosition(pose);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    block = blocks;
}

void SS :: render(RenderWindow &window)
{
    window.draw(sprite);
}