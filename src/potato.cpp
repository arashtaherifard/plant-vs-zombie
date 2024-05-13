#include"potato.hpp"

potato :: potato(Vector2f pose, int blocks)
{
    if (!image.loadFromFile("spriters/wall-nut/Wallnut_body.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    sprite.setScale(0.6, 0.6);
    sprite.setPosition(pose);
    block = blocks;
}

void potato :: render(RenderWindow &window)
{
    window.draw(sprite);
}
