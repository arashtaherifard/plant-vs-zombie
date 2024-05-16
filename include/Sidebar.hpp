#pragma once

#include "global.hpp"
#include "sidePeaShooter.hpp"
#include "sideSnowPea.hpp"
#include "sidePotato.hpp"
#include "Flower.hpp"
#include "sunStorage.hpp"

using namespace sf;
using namespace std;

class Sidebar {
public:
    Sidebar();
    void render(Event event, RenderWindow &window);
    void update(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated);
    void sunSetter(int store){sunStore += store;};
    int checkDrag(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated, int &storage);
    int sunGetter(){return sunStore;};
    void setText();
    
private:

    int sunStore = 0;
    Text storage;
    Font font;
    sunStorage *sun;
    sidePeaShooter *sidePeaShooters;
    sideSnowPea *sideSnowPeas;
    sideFlower *flowers;
    sidePotato *sidePotatos;
};