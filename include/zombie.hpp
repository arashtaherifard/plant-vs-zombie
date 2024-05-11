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
FloatRect getRect(){return sprite.getGlobalBounds();};
int life;
private:
Sprite sprite;
Texture image;
vector<int> y;
Vector2f pose;

};