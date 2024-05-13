#pragma once
#include"global.hpp"

using namespace std;
using namespace sf;

class PS{
public: 

PS(Vector2f pose, int count);
void update(Vector2f pose);
void render(RenderWindow  &window);
bool isDragging;
FloatRect getRect(){return sprite.getGlobalBounds();};
// void fixPosition();
Sprite sprite;
int life;
int block;

private:

Vector2f pose;
Texture image;

};