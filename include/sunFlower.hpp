#include"global.hpp"
using namespace std;
using namespace sf;

class SunFlower
{
public :

SunFlower(Vector2f pose, int blocks);
void render(RenderWindow  &window);
bool isCollided;
void collided();
FloatRect getRect(){return sprite.getGlobalBounds();};
int life;
int block;

private : 

Clock clock;
Sprite sprite;
Texture image;

};