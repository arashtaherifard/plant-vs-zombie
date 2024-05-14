#include"global.hpp"

using namespace sf;
using namespace std;
class SS
{
public :

SS(Vector2f pose, int blocks);
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