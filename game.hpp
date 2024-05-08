#include"peaShooter.cpp"
using namespace std;
using namespace sf;

class Game{
public:

Game(int width, int height);
~Game();
void run();
void checkMousePress();
RenderWindow window;

private:
// Music music;
Vector2f mousePose; 
PS *peaShooter;
Texture background;
void update();
void render();
bool isDraggimg;
Event event;
Sprite sprite;
void handleEvents();
void handleMousePress();
void handleMouseRelease();
}; 