#include "Sidebar.hpp"


Sidebar::Sidebar() 
{
    sun = new sunStorage(30, 10);
    flowers = new sideFlower(30,100);
    sidePeaShooters = new sidePeaShooter(30,170);
    sideSnowPeas = new sideSnowPea(30, 240);
    sidePotatos = new sidePotato(30,310);

}

void Sidebar::render(Event event, RenderWindow &window) 
{
    sidePotatos->render(event, window);
    sidePeaShooters->render(event, window);
    sideSnowPeas->render(event, window);
    flowers->render(event, window);
    sun->render(window);
}

void Sidebar :: update(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated)
{
    flowers->update(event, window, blocksPose, isGenerated);
    sidePotatos->update(event, window, blocksPose, isGenerated);
    sidePeaShooters->update(event, window, blocksPose, isGenerated);
    sideSnowPeas->update(event, window, blocksPose, isGenerated);
}



int Sidebar :: checkDrag(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated)
{   
    if (sidePotatos->checkDrag(event, window, blocksPose, isGenerated))
    {
        return sidePotatos->checkDrag(event, window, blocksPose, isGenerated);
    }
    if(sidePeaShooters->checkDrag(event, window, blocksPose, isGenerated))
    {
        return sidePeaShooters->checkDrag(event, window, blocksPose, isGenerated);
    }
    if(sideSnowPeas->checkDrag(event, window, blocksPose, isGenerated))
    {
        return sideSnowPeas->checkDrag(event, window, blocksPose, isGenerated);
    }
    if (flowers->checkDrag(event, window, blocksPose, isGenerated))
    {
        return flowers->checkDrag(event, window, blocksPose, isGenerated);
    }
    
}

// void Sidebar :: update(Event &event, RenderWindow &window)
// {
//     sidePotatos->update(event, window);
// }

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
