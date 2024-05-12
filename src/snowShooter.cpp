#include"snowShooter.hpp"

SS :: SS(Vector2f pose, int blocks)
{
    if (!image.loadFromFile("spriters/snow pea/HDplus_snowpea.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite . setScale(0.045, 0.045);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    sprite.setPosition(pose);
    block = blocks;
}

void SS :: render(RenderWindow &window)
{
    window.draw(sprite);
}