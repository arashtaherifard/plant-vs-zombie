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

void generate(Vector2f blocks, int &count);
void trashFiller(vector<bool> &isGenerated, vector<PS*> &trashPeaShooters, vector<SS*> &trashSnowShooters
, vector<potato*> &trashPotatos, vector<SunFlower*> &trashFlowers);
void deleter(vector<bool> &isGenerated);
int getPeaShootersCount(){return peaShooters.size();};
FloatRect getPeaShooterRect(int count){return peaShooters[count]->getRect();};

private:

vector < PS*> peaShooters;
vector < SS*> snowShooters;
vector < potato*> potatos;
vector < SunFlower*> flowers;
Clock clock;
};