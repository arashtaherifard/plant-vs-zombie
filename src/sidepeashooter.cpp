#include "sidePeaShooter.hpp"
#include "cmath"
sidePeaShooter::sidePeaShooter(float x, float y) 
{
    if (!texture.loadFromFile("spriters/images/icon_peashooter_100.png")||!fake.loadFromFile("spriters/Peashooter/Peashooter.png")) {
        return;
    }
    sprite.setTexture(texture);
    sprite.setScale(0.35,0.35);
    sprite.setPosition(x, y);

    isDragging = false;
    fakeSprite.setTexture(fake);
    fakeSprite.setOrigin(fakeSprite.getPosition().x+fakeSprite.getTextureRect().width/2 , fakeSprite.getPosition().x+fakeSprite.getTextureRect().height/2 );
    fakeSprite.setScale(0.04, 0.04);
    type = 1;
}

void sidePeaShooter :: render(Event &event, RenderWindow &window) 
{
    window.draw(sprite);
    if(isDragging)
    {
        window.draw(fakeSprite);
    }
}


int sidePeaShooter :: checkDrag(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated)
{
    Vector2f mousePose = Vector2f(Mouse::getPosition(window));
    if (event.type == Event :: MouseButtonPressed)
    { 
        if ((event.mouseButton.button == Mouse::Right || event.mouseButton.button == Mouse::Left )
        && sprite.getGlobalBounds().contains(mousePose))
        {
            isDragging = true;
        } 
    }
    else if(event.type == Event :: MouseButtonReleased)
    {
        isDragging = false; 
        if(fakeSprite.getGlobalBounds().contains(mousePose))
        {
            releasedPose = mousePose;
            changeStatus(blocksPose, isGenerated);
            return type;
        }
        else
        {
            return 0;
        }
    }
    return 0 ;
}

void sidePeaShooter :: dragAndDrop(Event &event, RenderWindow &window)
{
    Vector2f mousePose = Vector2f(Mouse::getPosition(window));
    if (isDragging)
    {
        fakeSprite.setPosition(mousePose);
    }
}


void sidePeaShooter :: update(Event &event, RenderWindow &window, vector <Vector2f> blocksPose, vector<bool> &isGenerated)
{
    if(isDragging)
    {
        dragAndDrop(event, window);
    }
}

int sidePeaShooter :: getDistance(Vector2f first, Vector2f second)
{
    return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
}

int sidePeaShooter :: changeStatus(vector <Vector2f> &blocksPose, vector<bool> &isGenerated)
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
    isGenerated[count] = true;
}
