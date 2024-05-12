#include "Sidebar.hpp"


Sidebar::Sidebar() 
{
    flowers = new Flower(30,100);
    sidePeaShooters = new sidePeaShooter(30,170);
    sideSnowPeas = new sideSnowPea(30, 240);
    sidePotatos = new sidePotato(30,310);
}

void Sidebar::render(RenderWindow &window) {

    sidePeaShooters->render(window);
    sideSnowPeas->render(window);
    flowers->render(window);
    sidePotatos->render(window);
}

/*void Sidebar::handleEvents(Event event, Vector2f mousePose) {
    if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
            for (auto &sidePeaShooter : sidePeaShooters) {
                if (sidePeaShooter.contains(mousePose)) {
                    // Do something when sidePeaShooter is clicked
                }
            }
            for (auto &sideSnowPea : sideSnowPeas) {
                if (sideSnowPea.contains(mousePose)) {
                    // Do something when sideSnowPea is clicked
                }
            }
            for (auto &flower : flowers) {
                if (flower.contains(mousePose)) {
                    // Do something when flower is clicked
                }
            }
        }
    }
}*/

// void Sidebar::addSidePeaShooter(float x, float y) {
//     sidePeaShooter->emplace_back(x, y);
// }

// void Sidebar::addSideSnowPea(float x, float y) {
//     sideSnowPea->emplace_back(x, y);
// }

// void Sidebar::addFlower(float x, float y) {
//     flower.emplace_back(x, y);
// }
