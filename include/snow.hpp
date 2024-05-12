#pragma once
#include "peaShooter.hpp"
using namespace std;
using namespace sf;
class Snow
{
public:

Snow(Vector2f pose);
void render(RenderWindow  &window);
void update();
FloatRect getRect(){return sprite.getGlobalBounds();};

private:

Sprite sprite;
Vector2f spritePose;
Texture image;

};