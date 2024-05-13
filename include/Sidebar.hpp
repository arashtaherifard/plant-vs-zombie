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
    int checkDrag(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated);
    // void handleEvents(Event event, Vector2f mousePose);
    //void addSidePeaShooter;
    //void addSideSnowPea;
    //void addFlower;
private:
    sunStorage *sun;
    sidePeaShooter *sidePeaShooters;
    sideSnowPea *sideSnowPeas;
    sideFlower *flowers;
    sidePotato *sidePotatos;
};