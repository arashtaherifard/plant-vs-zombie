#include"global.hpp"
#include"peaShooter.hpp"
#include"snowShooter.hpp"
#include"potato.hpp"
#include"sunFlower.hpp"
using namespace std;
using namespace sf;

class Player 
{
public :

void render(RenderWindow &window);
void generatePeaShooters(Vector2f blocks, int &count);
void generateSnowShooters(Vector2f blocks, int &count);
void generatePotatos(Vector2f blocks, int &count);
void generateFlowers(Vector2f blocks, int &count);
// void generate(Vector2f blocks, int &count);
void trashFiller(vector<bool> &isGenerated, vector<PS*> &trashPeaShooters, vector<SS*> &trashSnowShooters
, vector<potato*> &trashPotatos, vector<SunFlower*> &trashFlowers, vector<Vector2f> &trashPose, vector<Vector2f> &peaShootrerPose, vector<bool> &check);
void deleter(vector<bool> &isGenerated, vector<Vector2f> &peaShootrerPose, vector<bool> &check);
int getPeaShootersCount(){return peaShooters.size();};
int getSnowShootersCount(){return snowShooters.size();};
int getPotatoCount(){return potatos.size();};
int getSunFlowerCount(){return flowers.size();};
FloatRect getPeaShooterRect(int count);
FloatRect getSnowShooterRect(int count);
FloatRect getPotatoRect(int count);
FloatRect getSunFlowerRect(int count);
void peaShooterCollide(int count);
void snowShooterCollide(int count);
void potatoCollide(int count);
void sunFlowerCollide(int count);

private:

vector < PS*> peaShooters;
vector < SS*> snowShooters;
vector < potato*> potatos;
vector < SunFlower*> flowers;
Clock clock;
};