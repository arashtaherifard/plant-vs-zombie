#include "sidePotato.hpp"
#include "cmath"
sidePotato::sidePotato(float x, float y) 
{
    if (!sidePotatoTexture.loadFromFile("spriters/images/icon_walnut.png")||!fake.loadFromFile("spriters/wall-nut/Wallnut_body.png")
    ||!dimImage.loadFromFile("spriters/images/icon_walnut_dim.png")) {
        return;
    }
    sprite.setTexture(sidePotatoTexture);
    sprite.setScale(0.35,0.35);
    sprite.setPosition(x, y);

    isDragging = false;
    fakeSprite.setTexture(fake);
    fakeSprite.setOrigin(fakeSprite.getPosition().x+fakeSprite.getTextureRect().width/2 , fakeSprite.getPosition().x+fakeSprite.getTextureRect().height/2 );
    fakeSprite.setScale(0.6, 0.6);
    type = 3;
    dimSprite.setTexture(dimImage);
    dimSprite.setScale(0.35,0.35);
    dimSprite.setPosition(x,y);
    isDim = false;
}

void sidePotato::render(Event &event, RenderWindow &window) 
{
    
    if(isDim == false)
    {
        window.draw(sprite);
    }
    else if(isDim == true)
    {
        Time time = dimClock.getElapsedTime();
        if (time.asMilliseconds() >= 20000)
        {
            isDim = false;
            dimClock.restart();
        }
        window.draw(dimSprite);
    }
    if(isDragging && isDim == false)
    {
        window.draw(fakeSprite);
    }
}


int sidePotato :: checkDrag(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated, int &storage)
{
    if (storage<50)
    {
        isDim = true;
    }
    if (storage>=50)
    {
        isDim = false;
    }
    Vector2f mousePose = Vector2f(Mouse::getPosition(window));
    if (event.type == Event :: MouseButtonPressed)
    { 
        if ((event.mouseButton.button == Mouse::Right || event.mouseButton.button == Mouse::Left )
        && sprite.getGlobalBounds().contains(mousePose))
        {
            isDragging = true;
            return type;
        } 
    }
    else if(isDragging && event.type == Event :: MouseButtonReleased)
    {
        Vector2f mousePose = Vector2f(Mouse::getPosition(window));
        if(fakeSprite.getGlobalBounds().contains(mousePose))
        {
            releasedPose = mousePose;
            changeStatus(blocksPose, isGenerated, storage);
            isDragging = false; 
            return type;
        }
        else
        {
            isDragging = false; 
            return 0;
        }
    }
    return 0 ;
}

void sidePotato :: dragAndDrop(Event &event, RenderWindow &window)
{
    Vector2f mousePose = Vector2f(Mouse::getPosition(window));
    if (isDragging)
    {
        fakeSprite.setPosition(mousePose);
    }
}


void sidePotato :: update(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated)
{
    if(isDragging)
    {
        dragAndDrop(event, window);
    }
}

int sidePotato :: getDistance(Vector2f first, Vector2f second)
{
    return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
}

int sidePotato :: changeStatus(vector <Vector2f> &blocksPose, vector<bool> &isGenerated, int &storage)
{
    int count = 0;
    int distance = getDistance(releasedPose, blocksPose[0]);
    for (int i = 0; i < 45; i++)
    {
        if(i!=0)
        {
            if (getDistance(releasedPose, blocksPose[i]) <= distance)
            {
                count = i;
                distance = getDistance(releasedPose, blocksPose[i]);
            }
        }
    }
    if(storage >= 50)
    {
        isGenerated[count] = true;
        isDim = true;
    }
}
