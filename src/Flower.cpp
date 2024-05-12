#include "Flower.hpp"

Flower::Flower(float x, float y) {
    if (!flowerTexture.loadFromFile("spriters/images/icon_sunflower.png")) {
        return;
    }
    sprite.setTexture(flowerTexture);
    sprite.setScale(0.35,0.35);
    sprite.setPosition(x, y);
}

void Flower::render(RenderWindow &window) {
    window.draw(sprite);
}

bool Flower::contains(Vector2f point) {
    return sprite.getGlobalBounds().contains(point);
}
