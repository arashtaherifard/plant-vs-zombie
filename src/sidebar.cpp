#include "Sidebar.hpp"


Sidebar::Sidebar() 
{
    sun = new sunStorage(30, 10);
    flowers = new sideFlower(30,100);
    sidePeaShooters = new sidePeaShooter(30,170);
    sideSnowPeas = new sideSnowPea(30, 240);
    sidePotatos = new sidePotato(30,310);
    storage.setString(": ");

}

void Sidebar::render(Event event, RenderWindow &window) 
{
    
    sidePotatos->render(event, window);
    sidePeaShooters->render(event, window);
    sideSnowPeas->render(event, window);
    flowers->render(event, window);
    sun->render(window);
    setText();
    window.draw(storage);
}

void Sidebar :: update(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated)
{
    flowers->update(event, window, blocksPose, isGenerated);
    sidePotatos->update(event, window, blocksPose, isGenerated);
    sidePeaShooters->update(event, window);
    sideSnowPeas->update(event, window, blocksPose, isGenerated);   
}

void Sidebar :: setText()
{
    Font font;
    if(font.loadFromFile("spriters/font/ARIAL.ttf"))
    {
        return;
    }
    storage.setFont(font);
    storage.setString(": " + to_string(sunStore));
    storage.setCharacterSize(40);
    storage.setFillColor(Color::Black);
    storage.setPosition(100,40);

}

int Sidebar :: checkDrag(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated, int &storage)
{   
    int val = sidePeaShooters->checkDrag(event, window, blocksPose, isGenerated, storage);
    if (val)
    {
        return val;
    }
    val = sidePotatos->checkDrag(event, window, blocksPose, isGenerated, storage);
    if (val)
    {
        return val;
    }
    val = sideSnowPeas->checkDrag(event, window, blocksPose, isGenerated, storage);
    if (val)
    {
        return val;
    }
    val = flowers->checkDrag(event, window, blocksPose, isGenerated, storage);
    if (val)
    {
        return val;
    }
    if (val == 0)
    {
        return 0;
    }
    
    /*if (sidePotatos->checkDrag(event, window, blocksPose, isGenerated, storage))
    {
        return sidePotatos->checkDrag(event, window, blocksPose, isGenerated, storage);
    }
    else if(sidePeaShooters->checkDrag(event, window, blocksPose, isGenerated, storage))
    {
        return sidePeaShooters->checkDrag(event, window, blocksPose, isGenerated, storage);
    }
    else if(sideSnowPeas->checkDrag(event, window, blocksPose, isGenerated, storage))
    {
        return sideSnowPeas->checkDrag(event, window, blocksPose, isGenerated, storage);
    }
    else if (flowers->checkDrag(event, window, blocksPose, isGenerated, storage))
    {
        return flowers->checkDrag(event, window, blocksPose, isGenerated, storage);
    }
    else
    {
        return 0;
    }*/
}



