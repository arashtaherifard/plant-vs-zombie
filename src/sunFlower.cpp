#include"sunFlower.hpp"

SunFlower :: SunFlower(Vector2f pose, int blocks)
{
    if (!image.loadFromFile("spriters/sunflower/Sunflower.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    sprite.setScale(0.04, 0.04);
    sprite.setPosition(pose);
    block = blocks;
}


void SunFlower :: render(RenderWindow &window)
{
    window.draw(sprite);
}
