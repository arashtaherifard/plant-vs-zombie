#include"global.hpp"

using namespace std;
using namespace sf;

class PS{
public: 

PS(int x, int y);
void update();
void render(RenderWindow  &window);
void handleMousePress(Event &ev);
void handleMouseRelease(Event &ev);
private:
Sprite sprite;
Texture image;
};