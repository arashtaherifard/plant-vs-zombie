#include"global.hpp"

using namespace std;
using namespace sf;

class PS{
public: 

PS(int x, int y);
void update();
void render(RenderWindow  &window);
void handleMousePress(Vector2f mousePose);
void handleMouseRelease(Vector2f mousePose);
Sprite sprite;
Texture image;
private:


};