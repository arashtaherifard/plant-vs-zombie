#include"peaShooter.hpp"
PS :: PS(Vector2f pose, int count)
{
    if (!image.loadFromFile("spriters/Peashooter/Peashooter.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite.setScale(0.04, 0.04);
    sprite.setOrigin(sprite.getPosition().x+sprite.getTextureRect().width/2 , sprite.getPosition().x+sprite.getTextureRect().height/2 );
    sprite.setPosition(pose);
    life = 5;
    block = count;
}

// void PS :: fixPosition()
// {
//     FloatRect rect = sprite.getGlobalBounds();
//     rect.top = max(0.f, rect.top);
//     rect.top = min(rect.top, 600 - rect.height);
//     rect.left = max(0.f, rect.left);
//     rect.top = min(rect.top, 1400 - rect.width);
//     sprite.setPosition(rect.left, rect.top);
// }

void PS :: update(Vector2f mousePose)
{
    if (isDragging)
    {
        sprite.setPosition(mousePose);
    }
}

void PS :: render(RenderWindow &window)
{
    window.draw(sprite);
}