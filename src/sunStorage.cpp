#include "sunStorage.hpp"

sunStorage::sunStorage(float x, float y) 
{
    if (!sunTexture.loadFromFile("spriters/images/sun.png")) {
        return;
    }
    sprite.setTexture(sunTexture);
    sprite.setScale(0.7,0.7);
    sprite.setPosition(x, y);
}

void sunStorage::render(RenderWindow &window) 
{
    window.draw(sprite);
}

