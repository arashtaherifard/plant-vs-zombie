#pragma once
#include"zombie.hpp"
#include"snow.hpp"
class Handler
{
public :

void render(RenderWindow  &window);
void update(vector<Vector2f> pose);
void addZombies();
void addProjectiles(vector<Vector2f> pose);
void addSnows(vector<Vector2f> pose);
void deletedOutOfBounds(FloatRect windowBounds);

vector<FloatRect> getZombieRect()
{
    vector<FloatRect> result;
    for (int i = 0; i < zombies.size(); i++)
    {
        result.push_back(zombies[i]->getRect());
    }
    return result;
};

void setZombiePose(Vector2f pose, int count){zombies[count]->setPose(pose);};
void deleteZombies();
void isCollidedSetter(int count , bool is){zombies[count]->isCollidedSetter(is);};
int getZombiesCount(){return zombies.size();};

private : 

void collision();
vector <Zombie *> zombies;
vector <Projectile *> projectiles;
vector <Snow *> snows;
Clock Pclock;
Clock Zclock;
Clock Sclock;

};