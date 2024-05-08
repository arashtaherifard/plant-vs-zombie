#include"peaShooter.hpp"
PS :: PS(int x, int y)
{
    if (!image.loadFromFile("Peashooter.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite . setScale(0.045, 0.045);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2, sprite.getPosition().x+sprite.getTextureRect().height/2);
}

void PS :: handleMousePress(Vector2f mousePose)
{

    sprite.setPosition(mousePose.x, mousePose.y);
}

void PS :: handleMouseRelease(Vector2f mousePose)
{
    // sprite.setPosition(sprite.getPosition());
}

void PS :: render(RenderWindow &window)
{
    
    window.draw(sprite);
}