#include"global.hpp"

using namespace sf;
using namespace std;
class SS
{
public :

SS(Vector2f pose, int blocks);
void render(RenderWindow  &window);
int life;
int block;
private : 

Sprite sprite;
Texture image;

};