#include"game.hpp"

Game :: Game(int width, int height)
{
    window.create(VideoMode(width, height), "background", Style::Close);
    peaShooter = new PS(1,2);
    if(!background.loadFromFile("pictures/167822.png"))
    {
        return ;
    }
    sprite.setTexture(background);
    window.setFramerateLimit(144);
}

Game :: ~Game(){delete peaShooter;}

void Game :: render()
{
    window.clear();
    window.draw(sprite);
    peaShooter->render(window);
    window.display();  
} 

void Game :: checkMousePress()
{
    peaShooter->isDragging = false;
    if (event.mouseButton.button == Mouse::Right || event.mouseButton.button == Mouse::Left)
    {
        peaShooter->isDragging  = true;
    }
    if (!peaShooter->sprite.getGlobalBounds().contains(mousePose.x, mousePose.y))
    {
        peaShooter->isDragging  = false;
    }
}

void Game :: update()
{
    peaShooter->update(mousePose);
}

void Game :: handleMousePress()
{
    peaShooter->handleMousePress(mousePose);
}

void Game :: handleMouseRelease()
{
    peaShooter->handleMouseRelease(mousePose);
}

void Game :: handleEvents()
{
    if (peaShooter->isDragging )
    {
        mousePose =Vector2f(Mouse::getPosition(window));
        handleMousePress();
    }
    else 
    {
        handleMouseRelease();
    }
}
    


void Game :: run()
{
    while (window.isOpen())
    {
        while (window.pollEvent(event))
            {
                if (event.type == Event :: MouseButtonPressed)
                checkMousePress();
                if(event.type == Event :: MouseButtonReleased)
                peaShooter->isDragging  = false;
                if (event.type == Event::Closed)
                window.close();
                handleEvents();
            }
    render();
    update(); 
    }
}




