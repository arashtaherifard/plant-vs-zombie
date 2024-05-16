#include "Sidebar.hpp"


Sidebar::Sidebar() 
{
    sun = new sunStorage(30, 10);
    flowers = new sideFlower(30,100);
    sidePeaShooters = new sidePeaShooter(30,170);
    sideSnowPeas = new sideSnowPea(30, 240);
    sidePotatos = new sidePotato(30,310);
    
    if(!font.loadFromFile("spriters/font/MagicalNeverland.TTF"))
    {
        return;
    }
    storage.setFont(font);
    storage.setString(" : 000");
    storage.setCharacterSize(40);
    storage.setFillColor(Color::Black);
    storage.setOutlineThickness(1);
    storage.setOutlineColor(Color::White);
    storage.setStyle(sf::Text::Bold | sf::Text::Underlined);
    storage.setPosition(110,30);

}

void Sidebar::render(Event event, RenderWindow &window) 
{
    window.draw(storage);
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
    sidePeaShooters->update(event, window);
    sideSnowPeas->update(event, window, blocksPose, isGenerated);   
    setText();
}

void Sidebar :: setText()
{
    storage.setString(": " + to_string(sunStore));
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
    
}



