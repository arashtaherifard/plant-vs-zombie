#include "global.hpp"
using namespace std;
using namespace sf;
class Projectile
{
public:

Projectile();
void render(RenderWindow  &window);
void mover();

private:

Sprite sprite;
Vector2f spritePose;
Texture image;
};
