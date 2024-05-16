#pragma once
#include"zombie.hpp"
#include"snow.hpp"
#include"randomSun.hpp"
#include"giant.hpp"
class Handler
{
public :

void render(RenderWindow  &window);
void update(vector<Vector2f> peaShooterPose, vector<Vector2f> snowShooterPose);
void addZombies();

void addgiants();

void addProjectiles(vector<Vector2f> pose);
void addSnows(vector<Vector2f> pose);
void deletedOutOfBounds(FloatRect windowBounds);
void deleteZombies();
void deleteGiants();
void isCollidedSetter(int count , bool is){zombies[count]->isCollidedSetter(is);};
void giantCollidedSetter(int count , bool is){giants[count]->isCollidedSetter(is);};
void snowGenerator(vector<Vector2f> pose);
void peaGenerator(vector<Vector2f> pose);
int getZombiesCount(){return zombies.size();};
int getGiantsCount(){return giants.size();};
FloatRect getZombieRect(int count);
FloatRect getGiantRect(int count);
void generateRandomSuns();
void sunCollector(RenderWindow &window);
void deleteCollectedSuns(vector<RandomSun*> &trashSuns);
int sun;
void gameOver(bool &isOver, FloatRect windowBounds);

private : 

vector<RandomSun *> randomSuns;
void giantCollision();
void zombieCollision();
vector <Zombie *> zombies;
vector<Giant*> giants;
vector <Projectile *> projectiles;
vector <Snow *> snows;
Clock Pclock;
Clock Zclock;
Clock Sclock;
Clock Gclock;
Clock clock;
};