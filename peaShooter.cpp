#include"peaShooter.hpp"
PS :: PS(int x, int y)
{
    if (!image.loadFromFile("Peashooter.png"))
    {
        return;
    }
    sprite.setTexture(image);
    sprite . setScale(0.045, 0.045);
}

void PS :: render(RenderWindow &window)
{
    window.draw(sprite);
}