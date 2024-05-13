#pragma once

#include "global.hpp"

using namespace sf;

class sunStorage {
public:
    sunStorage(float x, float y);
    void render(RenderWindow &window);

private:
    Sprite sprite;
    Sprite dimSprite;
    Texture sunTexture;
};