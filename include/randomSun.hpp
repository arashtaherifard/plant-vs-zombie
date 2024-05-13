#pragma once
#include "global.hpp"

using namespace sf;
using namespace std;

class RandomSun
{
public:
    RandomSun();
    void render(RenderWindow &window);
    void update();

private:
    Sprite sunSprite;
    Texture sunTexture;
    Vector2f position;
    float fallSpeed;
    vector<int> x;

};
