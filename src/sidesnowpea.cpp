#include "sideSnowPea.hpp"
#include "cmath"
using namespace std;
sideSnowPea :: sideSnowPea(float x, float y) 
{
    if (!sideSnowTexture.loadFromFile("spriters/images/sideSnowPea.png")||!fake.loadFromFile("spriters/snow/HDplus_snowpea.png")) {
        return;
    }
    sprite.setTexture(sideSnowTexture);
    sprite.setScale(0.28,0.28);
    sprite.setPosition(x, y);

    isDragging = false;
    fakeSprite.setTexture(fake);
    fakeSprite.setOrigin(fakeSprite.getPosition().x+fakeSprite.getTextureRect().width/2 , fakeSprite.getPosition().x+fakeSprite.getTextureRect().height/2 );
    fakeSprite.setScale(0.06, 0.06);
    type = 2;
}

void sideSnowPea :: render(Event &event, RenderWindow &window) 
{
    window.draw(sprite);
    if(isDragging)
    {
        window.draw(fakeSprite);
    }
}


int sideSnowPea :: checkDrag(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated, int &storage)
{
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

void sideSnowPea :: dragAndDrop(Event &event, RenderWindow &window)
{
    Vector2f mousePose = Vector2f(Mouse::getPosition(window));
    if (isDragging)
    {
        fakeSprite.setPosition(mousePose);
    }
}


void sideSnowPea :: update(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated)
{
    if(isDragging)
    {
        dragAndDrop(event, window);
    }
}

int sideSnowPea :: getDistance(Vector2f first, Vector2f second)
{
    return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
}

int sideSnowPea :: changeStatus(vector <Vector2f> &blocksPose, vector<bool> &isGenerated, int &storage)
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
    if(storage >= 150)
    {
        isGenerated[count] = true;
    }
}

