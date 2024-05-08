// #include <SFML/Audio.hpp>
// #include <SFML/Graphics.hpp>
// #include <SFML/System.hpp>
#include"game.cpp"
// #include<iostream>
using namespace std;
using namespace sf;

bool checkPressed(Event e)
{       
    if (e.mouseButton.button == Mouse::Right)
    {
        return true;
    }
    return false;
}

bool checkMousePose(RenderWindow &window, Sprite z, bool checkPress)
{       
    Vector2f mousePose = Vector2f(Mouse::getPosition(window));
    if (z.getGlobalBounds().contains(mousePose.x, mousePose.y) && checkPress)
    {
        return true;
    }
    return false;
}

void drag(bool isDragging, Sprite &z, RenderWindow &window, Vector2f mousePose)
{

    if(isDragging)
    {
        z.setPosition(mousePose);
    }
}

int main()
{
   game zombieVsPlant(1400, 600);
   zombieVsPlant.run();
}