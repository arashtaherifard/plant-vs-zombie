#include "sideSnowPea.hpp"

sideSnowPea::sideSnowPea(float x, float y) {
    if (!sideSnowpeaTexture.loadFromFile("spriters/images/snowpeaicon.png")) {
        return;
    }
    sprite.setTexture(sideSnowpeaTexture);
    sprite.setScale(0.273,0.273);
    sprite.setPosition(x, y);
}

void sideSnowPea::render(RenderWindow &window) {
    window.draw(sprite);
}

bool sideSnowPea::contains(Vector2f point) {
    return sprite.getGlobalBounds().contains(point);
}
