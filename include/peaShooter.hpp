#pragma once
#include"global.hpp"

using namespace std;
using namespace sf;

class PS{
public: 

PS(Vector2f pose, int count);
void render(RenderWindow  &window);
bool isCollided;
void collided();
FloatRect getRect(){return sprite.getGlobalBounds();};
// void fixPosition();

int life;
int block;
bool isDim;
private:

Sprite sprite;
Clock clock;
Vector2f pose;
Texture image;

};