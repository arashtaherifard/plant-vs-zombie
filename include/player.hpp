#include"global.hpp"
#include"peaShooter.hpp"
#include"snowShooter.hpp"
#include"potato.hpp"
using namespace std;
using namespace sf;

class Player 
{
public :

void render(RenderWindow &window);
void generatePeaShooters(Vector2f blocks, int count);
void generateSnowShooters(Vector2f blocks, int count);
void generatePotatos(Vector2f blocks, int count);
void trashFiller(vector<bool> &isGenerated, vector<PS*> &trashPeaShooters, vector<SS*> &trashSnowShooters, vector<potato*> &trashPotatos);
void deleter(vector<bool> &isGenerated);

private:

vector < PS*> peaShooters;
vector < SS*> snowShooters;
vector < potato*> potatos;

};