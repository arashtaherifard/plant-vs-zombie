#include"peaShooter.cpp"
using namespace std;
using namespace sf;

class Game{
public:

Game(int width, int height);
~Game();
void run();
RenderWindow window;

private:
PS *peaShooter;
Texture background;
void update();
void render();
bool isDraggimg;
Event event;
Sprite sprite;
void handleEvents();
void handleMousePress(Event ev);
void handleMouseRelease(Event ev);
}; 