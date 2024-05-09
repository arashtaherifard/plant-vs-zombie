#include"projectile.cpp"

using namespace std;
using namespace sf;

class PS{
public: 

PS(int x, int y);
void update(Vector2f pose);
void render(RenderWindow  &window);
void handleMousePress(Vector2f pose);
void handleMouseRelease(Vector2f pose);
void generateProjectile();
bool isDragging;
Sprite sprite;
private:
Vector2f pose;
Texture image;
vector <Projectile *> projectiles;
Clock clock;
};