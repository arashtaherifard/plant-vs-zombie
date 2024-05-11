#pragma once
#include"handler.hpp"
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

Handler *handler;
// Music music;
Vector2f mousePose; 
vector<PS*> peaShooter;
Texture background;
void update();
void render();
Event event;
Sprite sprite;
vector<Vector2f>pose;
void poseSavor();
void handleEvents();
void handleMousePress();
void handleMouseRelease();
}; 