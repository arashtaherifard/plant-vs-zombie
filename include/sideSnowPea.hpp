#pragma once

#include "global.hpp"

using namespace sf;

class sideSnowPea {
public:
    sideSnowPea(float x, float y);
    void render(RenderWindow &window);
    bool contains(Vector2f point);

private:
    Sprite sprite;
    Sprite dimSprite;
    Texture sideSnowpeaTexture;
};