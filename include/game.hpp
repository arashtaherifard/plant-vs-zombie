#pragma once
#include"handler.hpp"
#include"player.hpp"
#include"Sidebar.hpp"
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
void generatePlants();
void update();
void render();
void sunHandler();
private:

vector<int> collision;
int storage;
int objectType;
Sidebar *sidebar;
Player *player;
vector<Vector2f> blockCenters;
vector<bool> isGenerated;
vector<bool> check;
Clock clock;
void PvsZ();
Handler *handler;
Music music;
Vector2f mousePose; 
Texture background;
Event event;
Sprite sprite;
vector<Vector2f>snowShooterPose;
vector<Vector2f>peaShooterPose;
void snowShooterPoseSavor(Vector2f blockCenter);
void peaShooterPoseSavor(Vector2f blockCenter);
void generator();
void handleEvents();
}; 