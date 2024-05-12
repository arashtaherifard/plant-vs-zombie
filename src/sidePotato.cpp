#include "sidePotato.hpp"

sidePotato::sidePotato(float x, float y) {
    if (!sidePotatoTexture.loadFromFile("spriters/images/icon_walnut.png")) {
        return;
    }
    sprite.setTexture(sidePotatoTexture);
    sprite.setScale(0.35,0.35);
    sprite.setPosition(x, y);
}

void sidePotato::render(RenderWindow &window) {
    window.draw(sprite);
}

bool sidePotato::contains(Vector2f point) {
    return sprite.getGlobalBounds().contains(point);
}
