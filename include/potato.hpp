#include"global.hpp"
using namespace std;
using namespace sf;

class potato
{
public :

potato(Vector2f pose, int blocks);
void render(RenderWindow  &window);
int life;
int block;

private : 

Sprite sprite;
Texture image;

};