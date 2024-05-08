#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class game{
public:

game(int width, int height);
void run();
RenderWindow window;

private:

Vector2f pos;
Texture background;
void update();
void render();
Event ev;
Sprite sprite;
void handleEvents();
void handleMousePress(Event ev);
void handleMouseRelease(Event ev);
}; 