#pragma once
#include"zombie.hpp"
class Handler
{
public :

void render(RenderWindow  &window);
void update(vector<Vector2f> pose);
void addZombies();
void addProjectiles(vector<Vector2f> pose);
void deleteds(FloatRect windowBounds);
private : 
void collision();

vector <Zombie *> zombies;
vector <Projectile *> projectiles;
Clock Pclock;
Clock Zclock;

};