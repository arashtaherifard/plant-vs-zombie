#pragma once
#include "projectile.hpp" 
using namespace std;
using namespace sf;
class Zombie
{
public :

Zombie();
void render(RenderWindow  &window);
void update();
void setPose(Vector2f pose){sprite.setPosition(pose);};
FloatRect getRect(){return sprite.getGlobalBounds();};
void isCollidedSetter(bool is){isCollided = is;};
int life;

private:

bool isCollided;
Sprite sprite;
vector<Texture> images;
vector<int> y;
Vector2f pose;
int currentFrame;
Clock frameClock;

};