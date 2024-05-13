#include"global.hpp"
using namespace std;
using namespace sf;

class SunFlower
{
public :

SunFlower(Vector2f pose, int blocks);
void render(RenderWindow  &window);
int life;
int block;

private : 

Sprite sprite;
Texture image;

};