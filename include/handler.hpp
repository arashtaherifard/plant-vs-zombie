#pragma once
#include"zombie.hpp"
#include"snow.hpp"
#include"randomSun.hpp"
class Handler
{
public :

void render(RenderWindow  &window);
void update(vector<Vector2f> peaShooterPose, vector<Vector2f> snowShooterPose);
void addZombies();
void addProjectiles(vector<Vector2f> pose);
void addSnows(vector<Vector2f> pose);
void deletedOutOfBounds(FloatRect windowBounds);

void setZombiePose(Vector2f pose, int count){zombies[count]->setPose(pose);};
void deleteZombies();
void isCollidedSetter(int count , bool is){zombies[count]->isCollidedSetter(is);};
void snowGenerator(vector<Vector2f> pose);
void peaGenerator(vector<Vector2f> pose);
int getZombiesCount(){return zombies.size();};
FloatRect getZobieRect(int count);
void generateRandomSuns();
void sunCollector(RenderWindow &window);
void deleteCollectedSuns(vector<RandomSun*> &trashSuns);
int sun;
private : 

vector<RandomSun *> randomSuns;
void collision();
vector <Zombie *> zombies;
vector <Projectile *> projectiles;
vector <Snow *> snows;
Clock Pclock;
Clock Zclock;
Clock Sclock;
Clock clock;
};