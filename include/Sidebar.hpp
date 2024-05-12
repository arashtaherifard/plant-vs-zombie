#pragma once

#include "global.hpp"
#include "sidePeaShooter.hpp"
#include "sideSnowPea.hpp"
#include "sidePotato.hpp"
#include "Flower.hpp"

using namespace sf;
using namespace std;

class Sidebar {
public:
    Sidebar();
    void render(RenderWindow &window);
    // void handleEvents(Event event, Vector2f mousePose);
    //void addSidePeaShooter;
    //void addSideSnowPea;
    //void addFlower;
private:
    sidePeaShooter *sidePeaShooters;
    sideSnowPea *sideSnowPeas;
    Flower *flowers;
    sidePotato *sidePotatos;
};