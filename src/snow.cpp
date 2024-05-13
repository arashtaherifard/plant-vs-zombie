#include"snow.hpp"
Snow :: Snow(Vector2f pose)
{
    if (!image.loadFromFile("spriters/snow/snow.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite.setScale(0.062,0.062);
    spritePose = pose;
}

void Snow  :: update()
{
    spritePose.x += 3 ; 
}

void Snow :: render(RenderWindow  &window)
{
    // sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    sprite.setPosition(spritePose.x + 30, spritePose.y - 22);
    update();
    window.draw(sprite);
}