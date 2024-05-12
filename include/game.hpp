#pragma once
#include"handler.hpp"
#include"player.hpp"
#include"sidebar.hpp"
using namespace std;
using namespace sf;

class Game{
public:

Game(int width, int height);
~Game();
void run();
void checkMousePress();
RenderWindow window;
void lineFiller();
void blocksPose(int count);
void generated();
void generateObjects(int type);

private:

Sidebar *sidebar;
Player *player;
vector<Vector2f> blockCenters;
vector<bool> isGenerated;
Clock clock;
void PvsZ(vector<FloatRect> zombiesRect);
Handler *handler;
Music music;
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