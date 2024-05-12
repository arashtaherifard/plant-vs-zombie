#include "sidePeaShooter.hpp"

sidePeaShooter::sidePeaShooter(float x, float y) {
    if (!sidepeaShooterTexture.loadFromFile("spriters/images/icon_peashooter_100.png")) {
        
        return;
    }
    sprite.setTexture(sidepeaShooterTexture);
    sprite.setScale(0.35,0.35);
    sprite.setPosition(x, y);
}

void sidePeaShooter::render(RenderWindow &window) {
    window.draw(sprite);
}

// bool sidePeaShooter::contains(Vector2f point) {
//     return sprite.getGlobalBounds().contains(point);
// }
